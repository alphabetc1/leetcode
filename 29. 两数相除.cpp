29. 两数相除.cpp
#define THRES 0X80000000

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!dividend)   {
            return 0;
        }else if(dividend == INT_MIN && divisor == -1)  {
            return INT_MAX;
        }

        bool flag = (dividend ^ divisor) < 0;
        unsigned int t = (dividend == INT_MIN? THRES: abs(dividend));
        unsigned int d = (divisor == INT_MIN? THRES: abs(divisor));

        unsigned int ans = 0;
        for(int i = 31; i >= 0; --i)    {
            if(t>>i >= d)   {
                ans += ((unsigned int)1 << i);
                t -= d<<i;
            }
        }
        if(ans == THRES)    {
            return INT_MIN;
        }
        return flag? -ans: ans;
    }
};

5522. 连通两组点的最小成本