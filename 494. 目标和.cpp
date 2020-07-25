494. 目标和.cpp
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        vector<vector<int>>dp(nums.size()+1, vector<int>(2001,0));
        dp[0][1000] = 1;
        for(int i = 1; i <= nums.size(); i++)   {
            for(int j = -1000; j <= 1000; j++)  {
                int first = 0, second = 0;
                if(j - nums[i-1] >= -1000 && j - nums[i-1] <= 1000) first = dp[i-1][j - nums[i-1]+1000];
                if(j + nums[i-1] >= -1000 && j + nums[i-1] <= 1000) second = dp[i-1][j + nums[i-1]+1000];
                dp[i][j+1000] += first + second;
            }
        }
        return S > 1000? 0: dp[nums.size()][S+1000];
    }
};