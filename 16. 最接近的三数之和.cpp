16. 最接近的三数之和.cpp
//双指针
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int res = nums[0] + nums[1] + nums[2];
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size() - 2; i++)    {
            int l = i+1, r = nums.size() - 1;
            while(l < r)   {
                int tmpSum = nums[i] + nums[l] + nums[r];
                if(fabs(target - tmpSum) < fabs(target - res))    {
                    res = tmpSum;
                }
                if(tmpSum < target) {
                    l++;
                }else if(tmpSum > target){
                    r--;
                }else{
                    return target;
                }
            }
        }
        return res;
    }
};