面试题14- II. 剪绳子 II.cpp
//最优解是每段长度为3，在这个基础上贪心
//如果每段切分为3后余数为1，则补在其中一个上使其长度为4
//如果余数为2，则另开一段，长度为2
class Solution {
public:
    int mod = 1000000007;

    long quickPow(int gap, int t) {
        long res = 1;
        long base = gap;
        while(t) {
            if((t & 1) == 1)    {
                res = (res * base) % mod;
            }
            base = (base * base) % mod;
            t >>= 1;
        }
        return res;
    }

    int cuttingRope(int n) {
        if(n <= 3)  return n-1;
        int t = n / 3, sur = n % 3;

        if(sur == 2)   {
            return (int)(quickPow(3, t) * 2 % mod);
        }else{
            return (int)((quickPow(3, t-1) * (3+sur)) % mod);
        }
    }
};