310. 最小高度树.cpp
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(1 == n)  {
            return {0};
        }
        vector<vector<int>> m(n);
        vector<int> degree(n, 0);
        for(int i = 0; i < edges.size(); i++)   {
            int u = edges[i][0];
            int v = edges[i][1];
            degree[u]++;
            degree[v]++;
            m[u].push_back(v);
            m[v].push_back(u);
        }

        queue<int> q;
        vector<int> res;
        for(int i = 0; i < n; i++)  {
            if(degree[i] == 1)  {
                q.push(i);
            }
        }

        while(!q.empty())   {
            res.clear();
            int size = q.size();

            for(int i = 0; i < size; i++)   {
                int top = q.front(); q.pop();
                res.push_back(top);

                for(int index:m[top])  {
                    degree[index]--;
                    if(degree[index] == 1)  {
                        q.push(index);
                    }
                }
            }   
        }
        return res;
    }
};