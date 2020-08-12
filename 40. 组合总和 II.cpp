40. 组合总和 II.cpp
/*关键是同一层不能出现相同元素比如
 1
2 2      //错误，第二层出现了两个2

  1
 2
2		 //正确，虽然出现了两个2，但是不在同一层
*/

class Solution {
public:
    vector<vector<int>> ans;    
    vector<int> path;

    void dfs(vector<int>& candidates, int index, int target)   {
        if(0 == target) {
            ans.push_back(path);
            return;
        }
        for(int i = index; i < candidates.size(); i++)  {
            if(i > index && candidates[i] == candidates[i-1])    {
                continue;
            }else if(target - candidates[i] < 0)    {
                return;
            }
            path.push_back(candidates[i]);
            dfs(candidates, i+1, target - candidates[i]);
            path.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(candidates, 0, target);
        return ans;
    }
};