5431. 给房子涂色 III.cpp
/*f[i][j][k]表示 (前i个房子,在第i个房子颜色为j,划分为k个街区) 时的最小花费
*/
int f[110][25][110];

class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        memset(f, 127, sizeof(f));
        f[0][0][0] = 0;

        for(int i = 0; i < m; i++)  {
            for(int j = 0; j <= n; j++)  {
                for(int k = 0; k <= target; k++) {
                    if(houses[i])   {
                        int x = houses[i];
                        f[i+1][x][k+(j != x)] = min(f[i+1][x][k+(j != x)], f[i][j][k]);
                    }else{
                        for(int x = 1; x <= n; x++) {
                            f[i+1][x][k+(x != j)] = min(f[i+1][x][k+(x != j)], f[i][j][k] + cost[i][x-1]);
                        }
                    }
                }
            }
        }

        int ans = 1 <<30;
        for(int j = 1; j <= n; j++)    {
            ans = min(ans, f[m][j][target]);
        }

        if(ans == 1 <<30)   {
            return -1;
        }else{
            return ans;
        }
    }
};
