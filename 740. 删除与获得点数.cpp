740. 删除与获得点数.cpp
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.empty())    {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int nowNum = nums[0], lastNum = 0;
        
        for(int i = 1; i < nums.size(); i++)    {
            if(nums[i] == nums[i-1])    {
                nowNum += nums[i];
            }else if (nums[i] == nums[i-1] + 1){
                int temp = lastNum;
                lastNum = max(lastNum, nowNum);
                nowNum = temp + nums[i];
            }else{
                lastNum = max(lastNum, nowNum);
                nowNum = max(nowNum, lastNum) + nums[i];
            }
        }
        return max(nowNum, lastNum);
    }
};