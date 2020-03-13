面试题 16.24. 数对和.cpp
//方法一：哈希
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        map<int, int> vis;
        vector<vector<int>> res;
        for(auto i : nums)  {
            if(vis[i]) {
                vis[i]--;
                res.push_back({target - i, i});
            }
            else vis[target - i]++;
        }
        return res;
    }
};

//方法二：双指针
class Solution {
public:
    vector<vector<int>> pairSums(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int i = 0, j = nums.size() - 1;
        while(i < j)    {
            int sum = nums[i] + nums[j];
            if(sum == target) {
                res.push_back({nums[i], nums[j]});
                i++; j--;
            }
            else if(sum < target)   {
                i++;
            }
            else j--;
        }
        return res;
    }
};