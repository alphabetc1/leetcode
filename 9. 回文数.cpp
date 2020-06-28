9. 回文数.cpp

class Solution {
public:
    string itoa(int i)  {
        stringstream tmp;
        tmp << i;
        return string(tmp.str());
    }

    bool isPalindrome(int x) {
        if(x < 0)   return false;
        string s1 = itoa(x), s2 = s1;

        reverse(s1.begin(), s1.end());
        
        return s1 == s2;
    }
};