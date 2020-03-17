面试题10- II. 青蛙跳台阶问题.cpp
//斐波那契
#define GAP 1000000007
class Solution {
public:
    int numWays(int n) {
        if(!n)  return 1;
        int left = 1, right = 1;
        for(int i = 2; i <= n; i++)     {
            int tmp = (left + right) % GAP;
            left = right;
            right = tmp;
        }
        return right;
    }
};