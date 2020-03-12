1071. 字符串的最大公因子.cpp
/*
辗转相除法
*/
class Solution {
public:
    int gcd(int a, int b)   {
        return b == 0?a:gcd(b, a%b);
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1 + str2 != str2 + str1)  return "";
        else return str1.substr(0, gcd(str1.size(), str2.size()));
    }
};