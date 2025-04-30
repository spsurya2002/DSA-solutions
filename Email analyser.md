# Python Script for EML File Analysis for Spam/Phishing Detection

Below is a Python script that analyzes an .eml file and generates a detailed markdown report with various factors that can help identify spam or phishing emails.

```python
import email
import email.policy
import re
import dns.resolver
import socket
import hashlib
import urllib.parse
from urlextract import URLExtract
import tldextract
import ipaddress
import datetime
import spf
import requests
from bs4 import BeautifulSoup
import whois
import json
import html2text
import warnings
from collections import Counter

# Suppress warnings for cleaner output
warnings.filterwarnings('ignore')

def analyze_eml(eml_file_path, output_md_path):
    # Initialize report dictionary
    report = {
        'basic_info': {},
        'headers_analysis': {},
        'content_analysis': {},
        'link_analysis': {'links': [], 'domains': [], 'redirects': []},
        'security_checks': {},
        'spam_indicators': {'score': 0, 'indicators': []},
        'phishing_indicators': {'score': 0, 'indicators': []}
    }

    # Read the EML file
    with open(eml_file_path, 'rb') as f:
        msg = email.message_from_binary_file(f, policy=email.policy.default)

    # Basic Information
    report['basic_info']['subject'] = msg.get('Subject', 'No Subject')
    report['basic_info']['from'] = msg.get('From', 'Unknown Sender')
    report['basic_info']['to'] = msg.get('To', 'Unknown Recipient')
    report['basic_info']['date'] = msg.get('Date', 'No Date')
    report['basic_info']['message_id'] = msg.get('Message-ID', 'No Message-ID')

    # Headers Analysis
    report['headers_analysis']['all_headers'] = dict(msg.items())
    report['headers_analysis']['received_headers'] = [h for h in msg.get_all('Received', [])]
    report['headers_analysis']['return_path'] = msg.get('Return-Path', None)
    report['headers_analysis']['reply_to'] = msg.get('Reply-To', None)
    report['headers_analysis']['x_headers'] = {k: v for k, v in msg.items() if k.lower().startswith('x-')}

    # Check for common spam headers
    spam_headers = {
        'X-Spam-Flag': 'YES',
        'X-Spam-Status': 'Yes',
        'X-Spam-Level': '*',
        'X-Spam-Score': lambda x: float(x) > 5.0
    }
    
    for header, condition in spam_headers.items():
        value = msg.get(header, None)
        if value:
            if callable(condition):
                if condition(value):
                    report['spam_indicators']['score'] += 1
                    report['spam_indicators']['indicators'].append(f"Spam header detected: {header} with value {value}")
            elif str(value).upper() == str(condition).upper():
                report['spam_indicators']['score'] += 1
                report['spam_indicators']['indicators'].append(f"Spam header detected: {header} with value {value}")

    # Content Analysis
    text_content = []
    html_content = []
    attachments = []
    
    for part in msg.walk():
        content_type = part.get_content_type()
        disposition = part.get('Content-Disposition', '')
        
        if 'attachment' in disposition:
            attachment_info = {
                'filename': part.get_filename(),
                'type': content_type,
                'size': len(part.get_payload(decode=True))
            }
            attachments.append(attachment_info)
        elif content_type == 'text/plain':
            text_content.append(part.get_content())
        elif content_type == 'text/html':
            html_content.append(part.get_content())
    
    report['content_analysis']['text_content'] = '\n'.join(text_content)
    report['content_analysis']['html_content'] = '\n'.join(html_content)
    report['content_analysis']['attachments'] = attachments
    
    # Convert HTML to plain text for analysis
    html_text = ''
    if html_content:
        h = html2text.HTML2Text()
        h.ignore_links = False
        html_text = h.handle(html_content[0])
    
    full_text = report['content_analysis']['text_content'] + '\n' + html_text
    
    # Analyze text for spam/phishing indicators
    spam_phrases = [
        'urgent action required', 'account suspension', 'password expired',
        'verify your account', 'click here', 'limited time offer',
        'you have won', 'prize claim', 'dear customer', 'dear account holder',
        'unusual activity', 'security alert', 'login to verify',
        'account verification', 'suspicious login attempt',
        'immediate action required', 'your account has been compromised',
        'banking details', 'credit card information', 'social security number',
        'password reset', 'confirm your identity', 'billing information',
        'invoice attached', 'payment due', 'overdue account'
    ]
    
    found_phrases = []
    for phrase in spam_phrases:
        if phrase.lower() in full_text.lower():
            found_phrases.append(phrase)
            report['spam_indicators']['score'] += 0.5
            report['phishing_indicators']['score'] += 0.5
    
    if found_phrases:
        report['spam_indicators']['indicators'].append(f"Found common spam/phishing phrases: {', '.join(found_phrases)}")
        report['phishing_indicators']['indicators'].append(f"Found common phishing phrases: {', '.join(found_phrases)}")
    
    # Check for urgency
    urgency_words = ['urgent', 'immediately', 'now', 'right away', 'asap', 'within 24 hours']
    urgency_count = sum(full_text.lower().count(word) for word in urgency_words)
    if urgency_count > 2:
        report['phishing_indicators']['score'] += 1
        report['phishing_indicators']['indicators'].append(f"High urgency language detected ({urgency_count} instances)")
    
    # Link Analysis
    extractor = URLExtract()
    all_links = extractor.find_urls(full_text)
    unique_links = list(set(all_links))
    
    for link in unique_links:
        link_info = {'original': link}
        
        # Parse URL components
        try:
            parsed = urllib.parse.urlparse(link)
            domain_info = tldextract.extract(parsed.netloc)
            
            link_info['domain'] = parsed.netloc
            link_info['path'] = parsed.path
            link_info['query'] = parsed.query
            link_info['fragment'] = parsed.fragment
            link_info['tld'] = domain_info.suffix
            link_info['registered_domain'] = f"{domain_info.domain}.{domain_info.suffix}"
            link_info['subdomain'] = domain_info.subdomain
            
            # Check for IP address in domain
            try:
                ipaddress.ip_address(parsed.netloc)
                link_info['is_ip'] = True
                report['phishing_indicators']['score'] += 1
                report['phishing_indicators']['indicators'].append(f"URL uses IP address directly: {link}")
            except ValueError:
                link_info['is_ip'] = False
            
            # Check for URL shortening
            shorteners = ['bit.ly', 'goo.gl', 'tinyurl.com', 'ow.ly', 't.co', 'is.gd', 'buff.ly', 'adf.ly']
            if any(s in parsed.netloc for s in shorteners):
                link_info['is_shortener'] = True
                report['phishing_indicators']['score'] += 0.5
                report['phishing_indicators']['indicators'].append(f"URL shortener detected: {link}")
            else:
                link_info['is_shortener'] = False
            
            # Check for suspicious characters
            if '@' in link or '//' in link.split('://')[1]:
                link_info['has_suspicious_chars'] = True
                report['phishing_indicators']['score'] += 1
                report['phishing_indicators']['indicators'].append(f"Suspicious characters in URL: {link}")
            else:
                link_info['has_suspicious_chars'] = False
            
            # Check for brand names in subdomains
            brands = ['paypal', 'microsoft', 'apple', 'amazon', 'ebay', 'bankofamerica', 'wellsfargo', 'chase']
            for brand in brands:
                if brand in link.lower() and brand not in link_info['registered_domain'].lower():
                    link_info['brand_in_subdomain'] = True
                    report['phishing_indicators']['score'] += 1
                    report['phishing_indicators']['indicators'].append(f"Brand name ({brand}) used in subdomain: {link}")
                    break
            else:
                link_info['brand_in_subdomain'] = False
            
        except Exception as e:
            link_info['error'] = str(e)
        
        report['link_analysis']['links'].append(link_info)
    
    # Domain Analysis
    domains = [link['domain'] for link in report['link_analysis']['links'] if 'domain' in link]
    domain_counter = Counter(domains)
    report['link_analysis']['domain_frequency'] = domain_counter.most_common()
    
    # Security Checks
    # SPF Check
    try:
        return_path = report['headers_analysis']['return_path']
        if return_path:
            domain = return_path.split('@')[-1].strip('>')
            received_headers = report['headers_analysis']['received_headers']
            if received_headers:
                last_received = received_headers[0]
                ip_match = re.search(r'\b(?:\d{1,3}\.){3}\d{1,3}\b', last_received)
                if ip_match:
                    ip = ip_match.group()
                    result = spf.check2(i=ip, s=return_path, h=domain)
                    report['security_checks']['spf'] = result[0]
                    if result[0] != 'pass':
                        report['spam_indicators']['score'] += 1
                        report['spam_indicators']['indicators'].append(f"SPF check failed: {result[0]}")
    except Exception as e:
        report['security_checks']['spf_error'] = str(e)
    
    # DKIM Check (simplified - would need full implementation)
    report['security_checks']['dkim'] = 'Not implemented (would require full DKIM verification)'
    
    # DMARC Check (simplified)
    report['security_checks']['dmarc'] = 'Not implemented (would require DMARC policy check)'
    
    # Generate Markdown Report
    with open(output_md_path, 'w', encoding='utf-8') as md_file:
        md_file.write(f"# Email Analysis Report\n\n")
        md_file.write(f"**File analyzed:** `{eml_file_path}`\n")
        md_file.write(f"**Analysis date:** {datetime.datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n\n")
        
        # Basic Info
        md_file.write("## Basic Information\n\n")
        md_file.write(f"- **Subject:** {report['basic_info']['subject']}\n")
        md_file.write(f"- **From:** {report['basic_info']['from']}\n")
        md_file.write(f"- **To:** {report['basic_info']['to']}\n")
        md_file.write(f"- **Date:** {report['basic_info']['date']}\n")
        md_file.write(f"- **Message-ID:** {report['basic_info']['message_id']}\n\n")
        
        # Headers Analysis
        md_file.write("## Headers Analysis\n\n")
        md_file.write("### Important Headers\n")
        md_file.write(f"- **Return-Path:** {report['headers_analysis']['return_path']}\n")
        md_file.write(f"- **Reply-To:** {report['headers_analysis']['reply_to']}\n\n")
        
        md_file.write("### Received Headers (Routing Information)\n")
        for i, received in enumerate(report['headers_analysis']['received_headers'], 1):
            md_file.write(f"{i}. `{received}`\n")
        md_file.write("\n")
        
        md_file.write("### X-Headers\n")
        for k, v in report['headers_analysis']['x_headers'].items():
            md_file.write(f"- **{k}:** {v}\n")
        md_file.write("\n")
        
        # Content Analysis
        md_file.write("## Content Analysis\n\n")
        md_file.write(f"**Text Content Length:** {len(report['content_analysis']['text_content'])} characters\n")
        md_file.write(f"**HTML Content Length:** {len(report['content_analysis']['html_content'])} characters\n\n")
        
        md_file.write("### Attachments\n")
        if report['content_analysis']['attachments']:
            for att in report['content_analysis']['attachments']:
                md_file.write(f"- **{att['filename']}** ({att['type']}, {att['size']} bytes)\n")
                # Check for executable attachments
                if att['filename'] and any(att['filename'].lower().endswith(ext) for ext in ['.exe', '.bat', '.js', '.vbs', '.ps1']):
                    report['spam_indicators']['score'] += 2
                    report['spam_indicators']['indicators'].append(f"Executable attachment detected: {att['filename']}")
        else:
            md_file.write("- No attachments found\n")
        md_file.write("\n")
        
        # Link Analysis
        md_file.write("## Link Analysis\n\n")
        md_file.write(f"**Total links found:** {len(report['link_analysis']['links'])}\n")
        md_file.write(f"**Unique domains:** {len(report['link_analysis']['domain_frequency'])}\n\n")
        
        md_file.write("### Suspicious Link Indicators\n")
        suspicious_links = [link for link in report['link_analysis']['links'] 
                           if any(link.get(key, False) for key in ['is_ip', 'is_shortener', 'has_suspicious_chars', 'brand_in_subdomain'])]
        
        if suspicious_links:
            for link in suspicious_links:
                md_file.write(f"- **URL:** {link['original']}\n")
                indicators = []
                if link.get('is_ip', False):
                    indicators.append("Uses IP address directly")
                if link.get('is_shortener', False):
                    indicators.append("URL shortening service")
                if link.get('has_suspicious_chars', False):
                    indicators.append("Contains suspicious characters (@ or //)")
                if link.get('brand_in_subdomain', False):
                    indicators.append("Brand name in subdomain")
                
                md_file.write(f"  - Indicators: {', '.join(indicators)}\n")
        else:
            md_file.write("- No obvious suspicious links found\n")
        md_file.write("\n")
        
        md_file.write("### Domain Frequency\n")
        for domain, count in report['link_analysis']['domain_frequency']:
            md_file.write(f"- `{domain}`: {count} {'time' if count == 1 else 'times'}\n")
        md_file.write("\n")
        
        # Security Checks
        md_file.write("## Security Checks\n\n")
        md_file.write(f"- **SPF:** {report['security_checks'].get('spf', 'Not checked')}\n")
        md_file.write(f"- **DKIM:** {report['security_checks'].get('dkim', 'Not checked')}\n")
        md_file.write(f"- **DMARC:** {report['security_checks'].get('dmarc', 'Not checked')}\n\n")
        
        # Spam Indicators
        md_file.write("## Spam Indicators\n\n")
        md_file.write(f"**Spam Score:** {report['spam_indicators']['score']}\n\n")
        
        if report['spam_indicators']['indicators']:
            md_file.write("### Detected Indicators\n")
            for indicator in report['spam_indicators']['indicators']:
                md_file.write(f"- {indicator}\n")
        else:
            md_file.write("No strong spam indicators detected\n")
        md_file.write("\n")
        
        # Phishing Indicators
        md_file.write("## Phishing Indicators\n\n")
        md_file.write(f"**Phishing Score:** {report['phishing_indicators']['score']}\n\n")
        
        if report['phishing_indicators']['indicators']:
            md_file.write("### Detected Indicators\n")
            for indicator in report['phishing_indicators']['indicators']:
                md_file.write(f"- {indicator}\n")
        else:
            md_file.write("No strong phishing indicators detected\n")
        md_file.write("\n")
        
        # Summary
        md_file.write("## Summary\n\n")
        if report['spam_indicators']['score'] > 5 or report['phishing_indicators']['score'] > 5:
            md_file.write("⚠️ **WARNING:** This email exhibits strong signs of being spam/phishing.\n")
        elif report['spam_indicators']['score'] > 2 or report['phishing_indicators']['score'] > 2:
            md_file.write("⚠️ **Caution:** This email shows some potential signs of being spam/phishing.\n")
        else:
            md_file.write("✅ This email appears to be legitimate based on the analysis.\n")
        
        md_file.write("\n### Recommendations\n")
        if report['spam_indicators']['score'] > 2 or report['phishing_indicators']['score'] > 2:
            md_file.write("- Do not click on any links in this email\n")
            md_file.write("- Do not download or open any attachments\n")
            md_file.write("- Verify the sender through other means if you're unsure\n")
            md_file.write("- Report this email as spam/phishing to your email provider\n")
        else:
            md_file.write("- This email appears safe, but always exercise caution with unexpected messages\n")

if __name__ == "__main__":
    import sys
    if len(sys.argv) != 3:
        print("Usage: python analyze_eml.py <input.eml> <output.md>")
        sys.exit(1)
    
    input_eml = sys.argv[1]
    output_md = sys.argv[2]
    
    print(f"Analyzing {input_eml}...")
    analyze_eml(input_eml, output_md)
    print(f"Analysis complete. Report saved to {output_md}")
```

## How to Use This Script

1. Save the script to a file named `analyze_eml.py`
2. Install the required dependencies:
   ```
   pip install email python-dns tldextract ipaddress spf pyurlextract html2text beautifulsoup4 requests whois
   ```
3. Run the script with your EML file:
   ```
   python analyze_eml.py input.eml report.md
   ```

## What This Script Analyzes

1. **Basic Information**:
   - Subject, From, To, Date, Message-ID

2. **Headers Analysis**:
   - All email headers
   - Received headers (for routing analysis)
   - Return-Path and Reply-To addresses
   - X-Headers (often used for spam filtering)

3. **Content Analysis**:
   - Text and HTML content
   - Attachments (with type and size)
   - Common spam/phishing phrases
   - Urgency indicators

4. **Link Analysis**:
   - All URLs in the email
   - Domain information
   - URL shortening services
   - Suspicious URL patterns
   - Brand impersonation in subdomains

5. **Security Checks**:
   - SPF verification (simplified)
   - DKIM and DMARC (noted as not fully implemented)

6. **Spam/Phishing Indicators**:
   - Scores based on detected patterns
   - Detailed list of suspicious elements

7. **Summary and Recommendations**:
   - Overall assessment
   - Safety recommendations

## Limitations

1. Some advanced checks (like full DKIM/DMARC verification) are not implemented due to complexity.
2. The script doesn't actually follow links (which could be dangerous with phishing emails).
3. Some spam/phishing detection is based on simple pattern matching which might generate false positives.

For production use, you might want to integrate with professional spam filtering services or more advanced machine learning models.
