200. 岛屿数量.cpp
class Solution {
public:
    int n, m;
    int fw[4][2] = {{0,1}, {0,-1}, {-1, 0}, {1, 0}};

    void bfs(vector<vector<char>>& grid, int col, int row)   {
        queue<int>q;
        q.push(col); q.push(row);
        grid[col][row] = '0';
        while(!q.empty())   {
            int topCol = q.front(); q.pop();
            int topRow = q.front(); q.pop();
            for(int i = 0; i < 4; i++)  {
                int newCol = topCol + fw[i][0];
                int newRow = topRow + fw[i][1];
                if(newCol < 0 || newCol >= n || newRow < 0 || newRow >= m || grid[newCol][newRow] == '0')  {
                    continue;
                } else{
                    grid[newCol][newRow] = '0';
                    q.push(newCol); q.push(newRow);
                }	
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        if(!grid.size() || !grid[0].size())  return 0;
        n = grid.size(), m = grid[0].size();
        int res = 0;
        
        for(int i = 0; i < n; i++)  {
            for(int j = 0; j < m; j++)  {
                if(grid[i][j] == '1')   {
                    res++;
                    bfs(grid, i, j);
                }
            }
        }
        return res;
    }
};