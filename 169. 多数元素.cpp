169. 多数元素.cpp
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 1, now = nums[0];
        for(int i = 1; i < nums.size(); i++)    {
            if(nums[i] == now)  count++;
            else{
                count--;
                if(count == 0)  {
                    now = nums[i];
                    count = 1;
                }
            }
        }
        return now;
    }
};