283. 移动零.cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        if(!nums.size())    {
            return;
        }
        int j = 0;
        for(int i = 0; i < nums.size(); i++)    {
            if(nums[i] != 0)    {
                if(i > j)   {
                    nums[j] = nums[i];
                    nums[i] = 0;
                }
                j++;
            }
        }
    }
};