329. 矩阵中的最长递增路径.cpp
class Solution {
public:
    int n, m, ans;
    int fw[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};

    int dfs(vector<vector<int>>& matrix, vector<vector<int>>& v, int col, int row) {
        if(v[col][row] != 1)    {
            return v[col][row];
        }

        for(int i = 0; i < 4; i++)  {
            int newCol = col + fw[i][0], newRow = row + fw[i][1];
            if(newCol < 0 || newCol >= n || newRow < 0 || newRow >= m)  {
                continue;
            }
            if(matrix[newCol][newRow] > matrix[col][row])   {
                v[col][row] = max(v[col][row], dfs(matrix, v, newCol, newRow) + 1);
            }
        }
        return v[col][row];
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if(!matrix.size() || !matrix[0].size()) return 0;

        n = matrix.size();
        m = matrix[0].size();
        ans = 1;

        vector<vector<int>>v(n, vector<int>(m, 1));
        for(int i = 0; i < n; i++)  {
            for(int j = 0; j < m; j++)  {
                ans = max(dfs(matrix, v, i, j), ans);
            }
        }
        return ans;
    }
};