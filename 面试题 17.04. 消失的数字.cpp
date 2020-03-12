面试题 17.04. 消失的数字.cpp
/*
根据异或的性质，x^y^y=x，也就是刚好出现偶数次的数会消失
那么我们对nums[0]:nums[n-1]和0：n分别异或一次，所得即为只出现过一次的数
*/
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();
        for(int i = 0; i < nums.size(); i++)    {
            ans ^= i;
            ans ^= nums[i];
        }
        return ans;
    }
};