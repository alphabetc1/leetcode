407. 接雨水 II.cpp
//类似双指针，不过这次是一圈
class Solution {
public:
    int fw[4][2] = {{1,0}, {-1,0}, {0,1}, {0,-1}};

    struct node{
        int height, col, row;
        bool operator < (const node &a)  const {
            return height > a.height;
        }
    };

    int trapRainWater(vector<vector<int>>& heightMap) {
        if(!heightMap.size() || !heightMap[0].size())   return 0;

        int n = heightMap.size();
        int m = heightMap[0].size();

        vector<vector<int>>v(n, vector<int>(m, 0));
        priority_queue<node>q;

        for(int i = 0; i < n; i++)   {
            q.push({heightMap[i][0], i, 0});
            q.push({heightMap[i][m-1], i, m-1});
            v[i][0] = v[i][m-1] = 1;
        }
        for(int i = 1; i < m-1; i++)    {
            q.push({heightMap[0][i], 0, i});
            q.push({heightMap[n-1][i], n-1, i});
            v[0][i] = v[n-1][i] = 1;
        }
        
        int ans = 0;
        while(!q.empty())   {
            auto [topHeight, topCol, topRow] = q.top(); q.pop();

            for(int i = 0; i < 4; i++)  {
                int nCol = topCol + fw[i][0];
                int nRow = topRow + fw[i][1];
                if(nCol < 0 || nCol >= n || nRow < 0 || nRow >= m || v[nCol][nRow])  {
                    continue;
                }
                if(heightMap[nCol][nRow] < topHeight)   {
                    ans += topHeight - heightMap[nCol][nRow];
                }
                q.push({max(topHeight, heightMap[nCol][nRow]), nCol, nRow});
                v[nCol][nRow] = 1;
            }
        }
        return ans;
    }
};