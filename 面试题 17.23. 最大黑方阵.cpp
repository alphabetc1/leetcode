面试题 17.23. 最大黑方阵.cpp
class Solution {
public:
    vector<int> findSquare(vector<vector<int>>& matrix) {
        vector<int> res(3,0);
        int n = matrix.size();
        if(!n)  return {};
        if(1 == n)  {
            if(matrix[0][0] == 0)   {
                res = {0,0,1};
            }
            else return {};
        }
        int dp[n][n][2];
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = dp[0][0][1] = 1-matrix[0][0];
        for(int i = 0; i < n; i++)  {
            for(int j = 0; j < n; j++)  {
                if(!matrix[i][j])    {
                    if(!i)  {dp[i][j][0] = 1;}
                    else{dp[i][j][0] = dp[i-1][j][0] + 1;}
                    if(!j)  {dp[i][j][1] = 1;}
                    else{dp[i][j][1] = dp[i][j-1][1] + 1;}
                }
                int len = min(dp[i][j][0], dp[i][j][1]);
                while(len > res[2])    {
                    if(dp[i-len+1][j][1] >= len && dp[i][j-len+1][0] >= len)  {
                        res = {i-len+1, j-len+1, len};
                        break;
                    }
                    len--;
                }
            }
        }
        return res;  
    }
};