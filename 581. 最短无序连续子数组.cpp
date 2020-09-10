581. 最短无序连续子数组.cpp
//双指针
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        if(nums.size() <= 1)    {
            return 0;
        }
        int left = 1, right = nums.size() - 2;
        int curMax = nums[0], curMin = nums[nums.size()-1];
        int leftTag = 1, rightTag = 0;
        while(left < nums.size() && right >= 0) {
            if(nums[left] < curMax) {
                rightTag = left;
            }else{
                curMax = nums[left];
            }
            left++;

            if(nums[right] > curMin)    {
                leftTag = right;
            }else{
                curMin = nums[right];
            }
            right--;
        }
        return rightTag - leftTag + 1;
    }
};