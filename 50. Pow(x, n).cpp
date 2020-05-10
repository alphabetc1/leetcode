50. Pow(x, n).cpp
class Solution {
public:
    double myPow(double x, int n) {
        double res = 1.0;
        for(int i = n; i != 0; i/= 2)   {
            if(i % 2 != 0)  {
                res *= x;
            }
            x *= x;
        }
        if(n < 0)   res = 1 / res;
        return res;
    }
};