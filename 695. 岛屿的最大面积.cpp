695. 岛屿的最大面积.cpp
//bfs
#define NMAX 60
class Solution {
public:
    int fw[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int bfs(vector<vector<int>>& grid, int row, int col)    {
        queue<pair<int,int>>q;
        grid[row][col] = 0;
        q.push({row, col});
        int count = 1;
        while(!q.empty())   {
            int oRow = q.front().first;
            int oCol = q.front().second;
            q.pop();
            for(int i = 0; i < 4; i++)  {
                int nRow = oRow + fw[i][0];
                int nCol = oCol + fw[i][1];
                if(nRow < 0 || nRow >= grid.size() || nCol < 0 || nCol >= grid[0].size())  continue;
                if(grid[nRow][nCol])    {
                    grid[nRow][nCol] = 0;
                    q.push({nRow,nCol});
                    count++;
                }
            }
        }
        return count;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++)    {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j])    {
                    ans = max(ans, bfs(grid, i, j));
                }
            }
        }
        return ans;
    }
};