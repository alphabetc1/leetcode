5457. 和为奇数的子数组数目.cpp
/*
**动态规划
**dp[i]表示前i个数相对于前i-1个增加了多少连续奇数子数组
**由于 奇 + 偶 = 奇
**如果第i个数为奇数，则dp[i] = dp[i-1]，它是第i-1个数作为奇数子数组(dp[i-1])的末尾
**如果第i个数为偶数，则dp[i] = i + 1 - dp[i-1]，它是第i-1个数作为偶数子数组(i - dp[i-1]))的末尾，加上它本身(1)
*/

class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long old = 0, ans = 0;
        for(int i = 0; i < arr.size(); i++)   {
            if(arr[i] & 1) {
                old = i + 1 - old;
            }
            ans += old;
        }
        return ans % 1000000007;
    }
};