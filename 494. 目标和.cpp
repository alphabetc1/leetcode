class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int sum = accumulate(nums.begin(), nums.end(), 0);
        if(S > sum || (S + sum) % 2 != 0) {
            return 0;
        }
        
        sum = (S + sum) / 2;

        vector<int> dp(sum+1);
        dp[0] = 1;

        int times = 1;
        for(int i = 0; i < nums.size(); ++i)    {
            if(!nums[i])    {
                times *= 2;
                continue;
            }
            for(int j = sum; j >= nums[i]; --j) {
                dp[j] += dp[j - nums[i]];
            }
        }

        return dp[sum] * times;
    }
};