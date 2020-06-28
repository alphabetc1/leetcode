面试题 08.11. 硬币.cpp

class Solution {
public:
    int waysToChange(int n) {
        int mod = 1000000007;
        int coins[4] = {25, 10, 5, 1};

        vector<long>dp(n+1);
        dp[0] = 1;

        for(int i = 0; i < 4; i++) {
            for(int j = coins[i]; j <= n; j++)  {
                dp[j] = (dp[j] + dp[j-coins[i]]) % mod;
            }
        }
        return dp[n];
    }
};