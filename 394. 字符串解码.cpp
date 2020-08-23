class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<int> numSt;
        stack<string> strSt;
        int num = 0;

        for(auto c:s)   {
            if(c <= '9' && c >= '0')    {
                num = num * 10 + c - '0';
            }else if(c == '[')  {
                numSt.push(num);
                num = 0;
                strSt.push(res);
                res = "";
            }else if(c == ']'){
                int t = numSt.top(); numSt.pop();
                for(int i = 0; i < t; i++)  {
                    strSt.top() += res;
                }
                res = strSt.top(); strSt.pop();
            }else{
                res += c;
            }
        }
        return res;
    }
};