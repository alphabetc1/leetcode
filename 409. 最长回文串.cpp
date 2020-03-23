409. 最长回文串.cpp
class Solution {
public:
    int longestPalindrome(string s) {
        map<int,int>v;
        int midFlag = 0, ans = 0;
        for(int i = 0; i < s.length(); i++) {
            v[s[i] - 'A']++;
            if(v[s[i] - 'A'] % 2 == 0)    {
                ans += 2;
            }
        }
        for(int i = 'A'; i <= 'z'; i++) {
            if(v[i - 'A'] % 2 == 1)     midFlag = 1;
        }
        return ans + midFlag;
    }
};