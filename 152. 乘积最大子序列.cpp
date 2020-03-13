152. 乘积最大子序列.cpp
//dp
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans, minSum, maxSum;
        ans = minSum = maxSum = nums[0];
        for(int i = 1; i < nums.size(); i++)    {
            if(nums[i] < 0) {
                int tmp = minSum;
                minSum = maxSum;
                maxSum = tmp;
            }
            minSum = min(nums[i], nums[i] * minSum);
            maxSum = max(nums[i], nums[i] * maxSum);
            ans = max(ans, maxSum);
        }
        return ans;
    }
};