413. 等差数列划分.cpp
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        if(A.size() < 3)    return 0;
        int res = 0;
        int st = 0;
        while(st < A.size() - 1)   {
            int ed = st + 1;
            for(; ed + 1 < A.size() && A[ed+1] - A[ed] == A[ed] - A[ed-1]; ed++);
            if(ed - st > 1)   {
                res += (ed - st -1)*(ed - st) / 2;
            }
            st = ed;
        }
        return res;
    }
};