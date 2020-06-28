713. 乘积小于K的子数组.cpp
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1)    return 0;
        int tmp = 1, res = 0;
        for(int left = 0, right = 0; right < nums.size(); right++)  {
            tmp *= nums[right];
            while(tmp >= k) {
                tmp /= nums[left];
                left++;
            }
            res += right - left + 1;
        }
        return res;
    }
};