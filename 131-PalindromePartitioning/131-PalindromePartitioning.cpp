            }
        }
        
        vector<vector<string>> result;
            for (int j = i; j < n; ++j) {
                if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                }
"aab"
"a"
[["a","a","b"],["aa","b"]]
[["a"]]
[["a","a","b"],["aa","b"]]
[["a"]]
"
