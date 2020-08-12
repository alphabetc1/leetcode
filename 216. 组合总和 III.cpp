216. 组合总和 III.cpp
class Solution {
public:
    vector<vector<int>> ans;
    vector<int> path;

    void dfs(int k, int n, int index, int indexNum, int sum)  {
        if(sum == n && indexNum == k)    {
            ans.push_back(path);
            return;
        }
        if(sum >= n || indexNum >= k || index > 9) {
            return;
        }
        for(int i = index; i <= 9; i++) {
            path.push_back(i);
            dfs(k, n, i+1, indexNum+1, sum + i);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(k, n, 1, 0, 0);
        return ans;
    }
};