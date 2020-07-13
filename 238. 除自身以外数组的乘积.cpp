238. 除自身以外数组的乘积.cpp
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>ans(nums.size(), 0);
        ans[0] = 1;

        for(int i = 1; i < nums.size(); i++)    {
            ans[i] = ans[i-1] * nums[i-1];
        }

        int right = 1;
        for(int i = nums.size()-1; i >= 0; i--) {
            ans[i] *= right;
            right *= nums[i];
        }

        return ans;
    }
};