            if (isPalindrome(s, index, i)) {
                path.push_back(s.substr(index, i - index + 1)); // Add current 
                partitionHelper(i + 1, s, path, res); // Recur for the remaining part
                path.pop_back(); // Backtrack and remove the last added substring
            }
        }
    }
substring
"aab"
"a"
[["a","a","b"],["aa","b"]]
[["a"]]
[["a","a","b"],["aa","b"]]
[["a"]]
"
