面试题12. 矩阵中的路径.cpp
#define NMAX 210
class Solution {
public:
    int n, m, vis[NMAX][NMAX] = {};
    int fw[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
    bool dfs(vector<vector<char>>& board, string word, int row, int col, int num)   {
        if(num == word.length())    return true;
        for(int i = 0; i < 4; i++)  {
            int nRow = row + fw[i][0];
            int nCol = col + fw[i][1];
            if(nRow < 0 || nRow >= n || nCol < 0 || nCol >= m || vis[nRow][nCol])  continue;
            if(board[nRow][nCol] == word[num])    {
                vis[nRow][nCol] = 1;
                if(dfs(board, word, nRow, nCol, num+1)) return true;
                vis[nRow][nCol] = 0;
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        for(int i = 0; i < n; i++)   {
            for(int j = 0; j < m; j++)    {
                if(board[i][j] == word[0])  {
                    memset(vis, 0, sizeof(vis));
                    vis[i][j] = 1;
                    if(dfs(board, word, i, j, 1)) return true;
                }
            }
        }
        return false;
    }
};