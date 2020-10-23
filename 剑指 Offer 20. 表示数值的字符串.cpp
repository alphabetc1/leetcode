剑指 Offer 20. 表示数值的字符串.cpp
class Solution {
private:
    // 整数的格式可以用[+|-]B表示, 其中B为无符号整数
    bool scanInteger(const string s, int& index){

        if(s[index] == '+' || s[index] == '-')
            ++index;

        return scanUnsignedInteger(s, index);
    }
    
    bool scanUnsignedInteger(const string s, int& index){

        int befor = index;
        while(index != s.size() && s[index] >= '0' && s[index] <= '9')
            index ++;

        return index > befor;
    }
public:
    // 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，
    // 其中A和C都是整数（可以有正负号，也可以没有），而B是一个无符号整数
    bool isNumber(string s) {

        if(s.size() == 0)
            return false;
        int index = 0;

        //字符串开始有空格，可以返回true
        while(s[index] == ' ')  //书中代码没有该项测试
            ++index;

        bool numeric = scanInteger(s, index);

        // 如果出现'.'，接下来是数字的小数部分
        if(s[index] == '.'){

            ++index;

            // 下面一行代码用||的原因：
            // 1. 小数可以没有整数部分，例如.123等于0.123；
            // 2. 小数点后面可以没有数字，例如233.等于233.0；
            // 3. 当然小数点前面和后面可以有数字，例如233.666
            numeric = scanUnsignedInteger(s, index) || numeric;
        }

        // 如果出现'e'或者'E'，接下来跟着的是数字的指数部分
        if(s[index] == 'e' || s[index] == 'E'){

            ++index;

            // 下面一行代码用&&的原因：
            // 1. 当e或E前面没有数字时，整个字符串不能表示数字，例如.e1、e1；
            // 2. 当e或E后面没有整数时，整个字符串不能表示数字，例如12e、12e+5.4
            numeric = numeric && scanInteger(s ,index);
        }

        //字符串结尾有空格，可以返回true
        while(s[index] == ' ')
            ++index;
        cout << s.size() << " " << index;   //调试用

        return numeric && index == s.size();
    }
};

class Solution {
public:
    int minimumOneBitOperations(int n) {
        int cnt[32];
        int res = 0;
        for(int i = 1; i < 31; i++) cnt[i-1] = (1 << i) - 1; // 规律1打表
        while(n) {
            int id1 = -1, id2 = -1;
            for(int i = 30; i >= 0; i--) { // 从高位开始遍历，寻找 1
                if((1 << i) & n) {
                    if(id1 == -1) id1 = i; // 记录较高位的 1
                    else if(id2 == -1) id2 = i; // 记录较低位的 1
                    else {
                        break; // 都找到了就 break
                    }
                }
            }
            if(id2 == -1) { // 只找到一个
                n ^= (1 << id1); // 消除这个 1
                res += cnt[id1]; // 规律 1
            }else {
                n ^= (1 << id1); // 消除 1
                n ^= (1 << id2); // 消除 1
                res += (cnt[id1] - cnt[id2]); // 规律 2 公式
            }
        }
        return res;
    }
};