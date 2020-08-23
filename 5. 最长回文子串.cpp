5. 最长回文子串.cpp
class Solution {
public:
    pair<int, int> extendFromMid(string s, int left, int right) {
        while(left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
        }
        return {left + 1, right - 1};
    }

    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for(int i = 0; i < s.size(); i++)   {
            auto [st1, ed1] = extendFromMid(s, i, i);
            auto [st2, ed2] = extendFromMid(s, i, i+1);
            if(ed1 - st1 > end - start) {
                start = st1;
                end = ed1;
            }
            if(ed2 - st2 > end - start) {
                start = st2;
                end = ed2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};