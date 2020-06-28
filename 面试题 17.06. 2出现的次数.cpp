面试题 17.06. 2出现的次数.cpp

class Solution {
public:
    int numberOf2sInRange(int n) {
        long base = 1, ans = 0;
        int pre = n / 10, now = n % 10, post = 0;
        
        while(post != n)    {
            if(now > 2)    {
                ans += (pre + 1) * base;
            }else if(now < 2)  {
                ans += pre * base;
            }else{
                ans += pre * base + post + 1;
            }

            post += base * now;
            now = pre % 10;
            pre /= 10;
            base *= 10;
        }
        return ans;
    }
};
