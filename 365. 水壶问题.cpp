365. 水壶问题.cpp
//找最大公约数
class Solution {
public:
    int gcd(int x, int y)   {
        return y == 0? x: gcd(y, x % y);
    }

    bool canMeasureWater(int x, int y, int z) {
        if(x + y < z)    {
            return false;
        }
        else if(x == z || y == z || x + y == z)   {
            return true;
        }
        else {
            return z % gcd(x,y) == 0;
        }
    }
};