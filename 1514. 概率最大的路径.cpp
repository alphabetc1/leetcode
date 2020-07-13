1514. 概率最大的路径.cpp
//dfs优化，一定注意now < 1e-5 不加过不了
class Solution {
public:
    double ans = 0;
    double last = 0;
    bool v[10005];
    vector<pair<int, double>> e[10005];

    void dfs(int start, int end, double now)  {
        if(start == end)    {
            ans = max(ans, now);
            return;
        }

        if(now < 1e-5 || now*last <= ans)   return;
        
        for(int i = 0; i < e[start].size(); i++)    {
            if(v[e[start][i].first])    {
                continue;
            }
            v[e[start][i].first] = 1;
            dfs(e[start][i].first, end, now * e[start][i].second);
            v[e[start][i].first] = 0;
        }
    }
    
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& s, int start, int end) {
        

        for(int i = 0; i < edges.size(); i++)   {
            e[edges[i][0]].push_back(make_pair(edges[i][1],s[i]));
            e[edges[i][1]].push_back(make_pair(edges[i][0],s[i]));
        }
        for(int i = 0; i < e[end].size(); i++)  {
            last = max(last, e[end][i].second);
        }

        v[start] = 1;
        dfs(start, end, 1);
        
        return ans;
    }
};

//dijkstra
class Solution {
public:
    vector<pair<int, double>>e[10005];
    bool vis[10005];

    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& s, int start, int end) {
        for(int i = 0; i < edges.size(); i++)   {
            e[edges[i][0]].push_back({edges[i][1], s[i]});
            e[edges[i][1]].push_back({edges[i][0], s[i]});
        }

        vector<double> dis(n, 0);
        dis[start] = 1;
        priority_queue<pair<double, int>>q;
        q.push({1, start});
        
        while(!q.empty())   {
            auto [topDis,topSt] = q.top(); q.pop();
            if(vis[topSt])  {
                continue;
            }

            vis[topSt] = 1;

            for(auto [newSt, newDis] : e[topSt])   {
                dis[newSt] = max(dis[newSt], dis[topSt]*newDis);
                q.push({dis[newSt], newSt});
            }
        }
        return dis[end];
        
    }
};