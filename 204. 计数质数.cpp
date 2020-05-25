204. 计数质数.cpp
class Solution {
public:
    int countPrimes(int n) {
        int res = 0;
        vector<int> v(n+2, 0);
        v[1] = 1;
        for(int i = 2; i*i < n ; i++) {
            if(!v[i])   {
                for(int j = i*i; j < n; j += i)    {
                    v[j] = 1;
                }
            }
        }
        for(int i = 1; i < n; i++)  {
            if(!v[i])   {
                res++;
            }
        }
        return res;
    }
};