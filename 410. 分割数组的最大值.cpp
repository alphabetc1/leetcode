410. 分割数组的最大值.cpp
class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        vector<vector<long>>dp(nums.size(), vector<long>(m+1, LONG_MAX));

        long now = 0;
        for(int i = 0; i < nums.size(); i++)    {
            now += nums[i];
            dp[i][1] = now;
        }

        for(int j = 2; j <= m; j++) {
            for(int i = 0; i < nums.size(); i++)    {
                long sum = 0;
                for(int k = i-1; k >= 0; k--)   {
                    sum += nums[k+1];
                    dp[i][j] = min(dp[i][j], max(dp[k][j-1], sum));
                    if(sum > dp[k][j-1])    {
                        break;
                    }
                }
            }
        }
        return (int)dp[nums.size()-1][m];
    }
};