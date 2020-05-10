560. 和为K的子数组.cpp
//hash
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        if(nums.size() == 0)    return 0;
        map<int, int> v;
        int sum = 0, res = 0;
        v[0] = 1;
        for(int i = 0; i < nums.size(); i++)    {
            sum += nums[i];
            if(v[sum - k]) res += v[sum - k];
            v[sum]++;
        }
        return res;
    }
};