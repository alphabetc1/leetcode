27. 移除元素.cpp
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int j = 0;
        for(int i = 0; i < nums.size(); i++)    {
            if(nums[i] != val)  {
                if(i > j)   {
                    nums[j] = nums[i];
                    nums[i] = val;
                }
                j++;
            }
        }
        return j;
    }
};