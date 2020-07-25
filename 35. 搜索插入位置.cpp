35. 搜索插入位置.cpp
//二分查找变体
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, ans = nums.size();
        while(l <= r)    {
            int mid = ((r - l) >> 1) + l;
            if(nums[mid] == target) {
                return mid;
            }else if(nums[mid] < target)    {
                l = mid + 1;
            }else{
                ans = mid;
                r = mid - 1;
            }
        }
        return l;
    }
};

//左侧边界
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r)    {
            int mid = l + ((r - l) >> 1);
            if(nums[mid] >= target) {
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};

//右侧边界
int right_bound(int[] nums, int target) {
    if (nums.length == 0) return -1;
    int left = 0, right = nums.length;

    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            left = mid + 1; // 注意
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }
    return left - 1; // 
}


