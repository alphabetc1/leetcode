15. 三数之和.cpp
//双指针
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());

        for(int i = 0; i < nums.size(); i++)  {
            if(i && nums[i] == nums[i-1])   continue;
            if(nums[i] > 0) break;
            int l = i+1, r = nums.size() - 1;
            while(l < r)   {
                int tmpSum = nums[i] + nums[l] + nums[r];
                if(tmpSum < 0)  {
                    l++;
                }else if(tmpSum > 0)    {
                    r--;
                }else{
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l < r && nums[l] == nums[l-1])   l++;
                    while(l < r && nums[r] == nums[r+1]) r--;
                }
            }
        }
        return res;
    }
};