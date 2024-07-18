        sum /= 2;

        vector<bool> dp(sum + 1, false);
        dp[0] = true; // Base case: a subset with sum 0 is always possible

        for (int i = 0; i < n; i++) {
            for (int j = sum; j >= nums[i]; j--) {
                dp[j] = dp[j] || dp[j - nums[i]];
            }
[
