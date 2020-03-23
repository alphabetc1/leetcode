887. 鸡蛋掉落.cpp
/*
dp[k][f]代表k个蛋在f次操作下能上多少层楼
在一层楼扔蛋有两种可能：碎了或者没碎
*/
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<int>dp(K + 1, 0);
        int ans = 0;
        while(dp[K] < N)    {
            for(int i = K; i > 0; i--)  {
                dp[i] = dp[i] + dp[i-1] + 1;
            }
            ans++;
        }
        return ans;
    }
};