18. 四数之和.cpp
//双指针
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++)    {
            if(i && nums[i] == nums[i-1])   continue;
            for(int j = i+1; j < nums.size(); j++)  {
                if(j && nums[j] == nums[j-1] && j-1 != i)   continue;
                int l = j+1, r = nums.size() - 1;
                while(l < r)    {
                    int tmp = nums[i] + nums[j] + nums[l] + nums[r];
                    if(tmp < target)    {
                        l++;
                    }else if(tmp > target)  {
                        r--;
                    }else{
                        res.push_back({nums[i], nums[j], nums[l], nums[r]});
                        l++;
                        r--;
                        while(l < r && nums[l] == nums[l-1])    l++;
                        while(l < r && nums[r] == nums[r+1])    r--;
                    }
                }
            }
        }
        return res;
    }
};