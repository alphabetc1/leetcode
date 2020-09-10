698. 划分为k个相等的子集.cpp
class Solution {
public:
    bool backtracking(vector<int> &nums, int k, int target, int cur, int start, vector<bool> &v)  {
        if(k == 0)  {
            return true;
        }
        if(target == cur) {
            return backtracking(nums, k-1, target, 0, 0, v);
        }
        for(int i = start; i < nums.size(); ++i)    {
            if(!v[i] && cur + nums[i] <= target)    {
                v[i] = true;
                if(backtracking(nums, k, target, cur + nums[i], i, v))  return true;
                v[i] = false;
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0, maxNum = 0;
        for(auto num:nums)  {
            sum += num;
            maxNum = max(maxNum, num);
        }
        if(sum % k != 0 || maxNum > sum / k)    {
            return false;
        }
        vector<bool> v(nums.size(), false);
        return backtracking(nums, k, sum/k, 0, 0, v);
    }
};