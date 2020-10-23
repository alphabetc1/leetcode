
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        if(!n)  {
            return 0;
        }

        vector<vector<long>> dp(n, vector<long> (m + 1, LONG_MAX));
        dp[0][1] = nums[0];
        for(int i = 1; i < nums.size(); ++i)    {
            dp[i][1] = nums[i] + dp[i-1][1];
        }

        for(int k = 2; k <= m; ++k) {
            for(int i = 0; i < n; ++i)  {
                long count = 0;
                for(int j = i - 1; j >= 0; --j) {
                    count += nums[j + 1];
                    dp[i][k] = min(dp[i][k], max(dp[j][k-1], count));

                    if(count > dp[j][k-1])  {
                        break;
                    }
                }
            }
        }

        return dp[n-1][m];
    }
};