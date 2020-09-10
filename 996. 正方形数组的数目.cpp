996. 正方形数组的数目.cpp
class Solution {
public:
    bool isSquare(int sum) {
        int tmp = sqrt(sum);
        return (tmp * tmp == sum);
    }

    void dfs(vector<int> &nodes, map<int, int> &counts, vector<vector<int>> &g, int index, int need, int &ans)  {
        if(need == 0)   {
            ++ans;
            return;
        }
        for(auto i: g[index])   {
            if(counts[nodes[i]] > 0)   {
                --counts[nodes[i]];
                dfs(nodes, counts, g, i, need-1, ans);
                ++counts[nodes[i]];
            }
        }
    }

    int numSquarefulPerms(vector<int>& A) {
        map<int, int> counts;
        for(auto num:A) {
            ++counts[num];
        }

        vector<int> nodes;
        for(auto& p:counts) {
            nodes.push_back(p.first);
        }

        vector<vector<int>>g(nodes.size());
        for(int i = 0; i < nodes.size(); ++i)   {
            if(counts[nodes[i]] > 1 && isSquare(2 * nodes[i]))  {
                g[i].push_back(i);
            }
            for(int j = i+1; j < nodes.size(); ++j) {
                if(isSquare(nodes[i] + nodes[j])) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < nodes.size(); ++i)   {
            --counts[nodes[i]];
            dfs(nodes, counts, g, i, A.size()-1, ans);
            ++counts[nodes[i]];
        }
        return ans;
    }
};