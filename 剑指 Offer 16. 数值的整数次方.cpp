剑指 Offer 16. 数值的整数次方.cpp
class Solution {
public:
    double myPow(double x, int n) {
        if(!x)  return 0;
        long tmp = n;
        if(tmp < 0)   {
            x = 1/x;
            tmp *= -1;
        }
        double ans = 1;
        while(tmp)    {
            if(tmp & 1)   {
                ans *= x;
            }
            tmp >>= 1;
            x *= x;
        }
        return ans;
    }
};