214. 最短回文串.cpp
class Solution {
public:
    vector<int> dp;

    void getDp(string &s)    {
        string str(s.size() * 2 + 1, '1');
        for(int i = 0; i < s.size(); ++i)   {
            str[i<<1|1] = s[i];
        }

        dp.resize(str.size());
        int left = 0, right = -1;
        for(int i = 0; i < str.size(); ++i) {
            if(i <= right)  {
                dp[i] = min((right - i) * 2 + 1, dp[left + right - i]);
            }else{
                dp[i] = 1;
            }
            int lt = i - (dp[i]>>1) - 1, rt = i + (dp[i]>>1) + 1;
            while(lt >= 0 && rt < str.size() && str[lt] == str[rt]) {
                --lt;
                ++rt;
            }
            dp[i] = rt - lt - 1;
            if(rt > right)  {
                left = lt + 1;
                right = rt - 1;
            }
        }
    }

    bool isPalindrome(int left, int right)   {
        left = (left << 1) + 1;
        right = (right << 1) + 1;
        int mid = ((right - left) >>1) + left;
        return (mid >= 0 && mid < dp.size() && dp[mid] >= right - left + 1);
    }

    string shortestPalindrome(string s) {
        if(s.size() <= 0)   {
            return s;
        }
        getDp(s);
        
        for(int i = s.size() - 1; i >= 0; --i)   {
            if(isPalindrome(0, i))  {
                auto str = s.substr(i+1);
                reverse(str.begin(), str.end());
                return str + s;
            }
        }
        
        return s;
    }
    
};