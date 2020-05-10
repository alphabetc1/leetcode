1337. 方阵中战斗力最弱的 K 行.cpp
class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>>m;
        for(int i = 0; i < mat.size(); i++) {
            int sum = accumulate(mat[i].begin(), mat[i].end(), 0);
            m.push_back({sum, i});
        }
        sort(m.begin(), m.end());
        vector<int>res;
        for(int i = 0; i < k; i++)  {
            res.push_back(m[i].second);
        }
        return res;
    }
};