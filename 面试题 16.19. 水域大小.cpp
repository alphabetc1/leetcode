面试题 16.19. 水域大小.cpp
//bfs
class Solution {
public:
    vector<int> pondSizes(vector<vector<int>>& land) {
        int n, m;
        int fw[8][2] = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        vector<int> ans;
        n = land.size();
        m = land[0].size();
        for(int i = 0; i < n; i++)    {
            for(int j = 0; j < m; j++)    {
                if(!land[i][j])  {    
                    queue<pair<int, int>>q;
                    q.push({i, j});
                    land[i][j] = 1;
                    int count = 1;
                    while(!q.empty())   {
                        int topRow = q.front().first;
                        int topCol = q.front().second;
                        q.pop();
                        for(int i = 0; i < 8; i++)  {
                            int newRow = topRow + fw[i][0];
                            int newCol = topCol + fw[i][1];
                            if(newRow < 0 || newRow >= n || newCol < 0 || newCol >= m)  continue;
                            if(!land[newRow][newCol])   {
                                count++;  
                                q.push({newRow,newCol});
                                land[newRow][newCol] = 1;
                            }
                        }
                    }
                    ans.push_back(count);            
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};