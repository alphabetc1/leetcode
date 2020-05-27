446. 等差数列划分 II - 子序列.cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int res = 0;
    
        vector<map<int, int>> v(A.size());
        for(int i = 1; i < A.size(); i++)   {
            long num = A[i];
            for(int j = 0; j < i; j++)  {
                if(num - A[j] > INT_MAX)    continue;
                if(num - A[j] < INT_MIN)    continue;
                int gap = A[i] - A[j];
                if(v[j].find(gap) != v[j].end()) {  //说明在第j个数时以gap为delta的等差数列长度至少为2
                    v[i][gap] += v[j][gap] + 1;
                    res += v[j][gap];
                }else{
                    v[i][gap]++;
                }
            }
        }
        return res;
    }
};