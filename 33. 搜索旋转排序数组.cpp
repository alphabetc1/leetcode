33. 搜索旋转排序数组.cpp
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size()-1;
        while(left <= right) {
            int mid = ((right - left)>>1) + left;
            if(nums[mid] == target) {
                return mid;
            }  
            if(nums[mid] < nums[right]) {
                if(target < nums[mid])  {
                    right = mid - 1;
                }else if(target > nums[mid] && target <= nums[right])   {
                    left = mid + 1;
                }else if(target > nums[right])  {
                    right = mid - 1;
                }
            }else{
                if(target > nums[mid]) {
                    left = mid + 1;
                }else if(nums[right] < target && target < nums[mid])    {
                    right = mid - 1;
                }else if(target <= nums[right]) {
                    left = mid + 1;
                }
            }
        }
        return -1;
    }
};