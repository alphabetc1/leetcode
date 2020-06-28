70. 爬楼梯.cpp
//经典dp
class Solution {
public:
    int climbStairs(int n) {
        if(n == 1)  return 1;
        else if(n == 2) return 2;
        
        int l_1 = 1, l_2 = 2;
        for(int i = 3; i <= n; i++) {
            int tmp = l_1 + l_2;
            l_1 = l_2;
            l_2 = tmp;
        }
        return l_2;
    }
};