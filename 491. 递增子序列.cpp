491. 递增子序列.cpp
class Solution {
public:
    vector<vector<int>> res;

    void dfs(vector<int>& nums, int index, vector<int> dp)  {
        if(index >= nums.size())    {
            if(dp.size() >= 2)  {
                res.push_back(dp);
            }
            return;
        }
        if(dp.empty() || nums[index] >= dp.back())  {
            dp.push_back(nums[index]);
            dfs(nums, index+1, dp);
            dp.pop_back();
        }
        if(index > 0 && !dp.empty() && nums[index] == dp.back())    return;
        dfs(nums, index+1, dp);
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        
        vector<int>dp;
        dfs(nums, 0, dp);
        
        return res;
    }
};
