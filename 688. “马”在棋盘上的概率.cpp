688. “马”在棋盘上的概率.cpp
/*图dp，类似 576. 出界的路径数
**这题描述有问题：按照标准答案马在棋盘外也可以走，即第K步一共有8^K种可能
*/
class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        if(K == 0)  return 1;
        vector<vector<vector<double>>> inDp(N+4, vector<vector<double>>(N+4, vector<double>(K+1, 0)));
       
        for(int i = 2; i <= N+1; i++) {
            for(int j = 2; j <= N+1; j++) {
                inDp[i][j][0] = 1;
            }
        }

        for(int t = 1; t <= K; t++) {
            for(int i = 2; i <= N+1; i++) {
                for(int j = 2; j <= N+1; j++) {
                    inDp[i][j][t] = (inDp[i-2][j-1][t-1]+inDp[i-1][j-2][t-1]+inDp[i+1][j+2][t-1]+inDp[i+2][j+1][t-1]
                    +inDp[i-2][j+1][t-1]+inDp[i-1][j+2][t-1]+inDp[i+2][j-1][t-1]+inDp[i+1][j-2][t-1]) / 8.0;
                }
            }
            
        }
    
        return inDp[r+2][c+2][K];
    }
};

