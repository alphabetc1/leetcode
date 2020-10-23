132. 分割回文串 II.cpp
class Solution {
public:
    int ans;
    vector<int> cnt;

    void getCnt(string &s)    {
        string str(s.size() * 2 + 1, '#');
        for(int i = 0; i < s.size(); ++i)   {
            str[i<<1|1] = s[i];
        }

        int left = 0, right = -1;
        for(int i = 0; i < str.size(); ++i) {
            if(i <= right)  {
                cnt[i] = min((right - i) * 2 + 1, cnt[left + right - i]);
            }else{
                cnt[i] = 1;
            }
            int lt = i - (cnt[i]>>1) - 1, rt = i + (cnt[i]>>1) + 1;
            while(lt >= 0 && rt < str.size() && str[lt] == str[rt]) {
                --lt;
                ++rt;
            }
            cnt[i] = rt - lt - 1;
            if(rt > right)  {
                left = lt + 1;
                right = rt - 1;
            }
        }
    }

    inline bool isPalindrome(int left, int right)  {
        left = 2 * left + 1;
        right = 2 * right + 1;
        int mid = ((right - left)>>1) + left;
        return (mid >= 0 && mid < cnt.size() && cnt[mid] >= right - left + 1);
    }

    int minCut(string s) {
        cnt.resize(s.size() *  2 + 1);
        getCnt(s);
        ans = s.size();

        vector<int> dp(s.size(), 10000);
        for(int i = 0; i < dp.size(); ++i)  {
            if(isPalindrome(0, i))  {
                dp[i] = 1;
                continue;
            }
            for(int j = 0; j < i; ++j)  {
                if(isPalindrome(j+1, i))  {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }

        return dp[s.size()-1]-1;
    }
};