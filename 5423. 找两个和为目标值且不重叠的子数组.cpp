5423. 找两个和为目标值且不重叠的子数组.cpp
class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        vector<int>dp(arr.size()+1, INT_MAX);
        map<int, int>v;
        v[0] = -1;

        int sum = 0, res = INT_MAX;

        for(int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            dp[i+1] = dp[i];
            if(v.count(sum - target))   {
                if(dp[v[sum-target]+1] != INT_MAX)   {
                    res = min(res, dp[v[sum - target]+1]+i - v[sum-target]);
                }
                dp[i+1] = min(dp[i+1], i - v[sum-target]);
            }
            v[sum] = i;
        }
        if(res == INT_MAX)  return -1;
        else return res;
    }
};