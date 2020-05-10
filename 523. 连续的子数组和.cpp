523. 连续的子数组和.cpp
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        map<int, int> v;
        int res = 0, sum = 0;
        v[0] = -1;
        for(int i = 0; i < nums.size(); i++)    {
            sum += nums[i];
            if(k)  sum %= k;
            if(v.count(sum))  {
                if(i - v[sum] > 1)  {
                    return true;
                }
            }else{
                v[sum] = i;
            }     
        }
        return false;
    }
};