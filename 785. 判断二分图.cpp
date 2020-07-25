785. 判断二分图.cpp
class Solution {
public:
    bool dfs(vector<vector<int>>& graph, vector<int> &v, int st) {
        bool flag = true;
        for(auto num:graph[st]) {
            if(v[num] == v[st]) {
                return false;
            }else if(v[num] == 2)    {
                v[num] = 1-v[st];
                flag &= dfs(graph, v, num);
            }
        }
        return flag;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
       vector<int>v(graph.size(), 2); 
       for(int i = 0; i < graph.size(); i++)    {
           if(v[i] == 2)    {
               v[i] = 0;
               if(!dfs(graph, v, i))    {
                   return false;
               }
           }
       }
       return true;
    }
};