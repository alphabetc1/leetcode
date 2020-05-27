974. 和可被 K 整除的子数组.cpp
class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int sum = 0, res = 0;
        map<int, int>v;
        v[0] = 1;

        for(int i = 0; i < A.size(); i++)   {
            sum = (A[i] + sum) % K;
            while(sum < 0) {
                sum += K;
            }
            if(v.count(sum % K))    {
                res += v[sum % K];
                v[sum % K]++;
            }else{
                v[sum % K] = 1;
            }
        }
        return res;
    }
};