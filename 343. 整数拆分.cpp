343. 整数拆分.cpp
/*
采用均分的思想cpp/100/100
*/
class Solution {
public:
    int integerBreak(int n) {
        int ans = 0;
        for(int k = sqrt(n) ; k <= n; k++) {
            if(1 == k)  continue;
            int gap = n / k;
            int tmpAns = 1, tmpN = n - k * gap;
            for(int j = 0; j < k; j++)  {
                if(tmpN)    {
                    tmpAns *= gap+1;
                    tmpN--;
                }
                else tmpAns *= gap;
            }
            ans = max(ans, tmpAns);    
        }
        return ans;
    }
};