416. 分割等和子集.cpp
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(auto num:nums)  {
            sum += num;
        }
        if(sum % 2 != 0)    {
            return false;
        }
        sum /= 2;
        vector<bool> dp(sum+1, false);
        dp[0] = true;
        for(int i = 0; i < nums.size(); i++)    {
            for(int j = sum; j >= nums[i]; j--)   {
                if(dp[sum]) {
                    return true;
                }
                dp[j] = dp[j] | dp[j - nums[i]];
            }
        }
        return dp[sum];
    }
};