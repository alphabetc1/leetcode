1027. 最长等差数列.cpp
class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int res = 0;
    
        vector<map<int, int>> v(A.size());
        for(int i = 1; i < A.size(); i++)   {
            for(int j = 0; j < i; j++)  {
                int gap = A[i] - A[j];
                if(v[j].count(gap)) {
                    v[i][gap] = v[j][gap] + 1;
                }else{
                    v[i][gap] = 2;
                }
                res = max(res, v[i][gap]);
            }
        }
        return res;
    }
};