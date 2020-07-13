32. 最长有效括号.cpp
//栈做法。用栈顶元素代表[上一个未被匹配的右括号]，初始设置为-1
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans = 0;
        stack<int>st;   
        st.push(-1);

        for(int i = 0; i < s.size(); i++)   {
            if(s[i] == '(')    {
                st.push(i);
            }else{
                st.pop();
                if(st.empty())  {
                    st.push(i);
                }else{
                    ans = max(ans, i - st.top());
                }
            }
        }
        return ans;
    }
};

//动态规划，dp[i]表示以i结尾的最长合法数量
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.size() < 2)    return 0;

        vector<int>dp(s.size(), 0);
        if(s[0] == '(' && s[1] == ')')  dp[1] = 2;

        for(int i = 2; i < s.size(); i++)   {
            if(s[i] == ')') {
                if(s[i-1] == '(')   {
                    dp[i] = dp[i-2]+2;
                }else if(i-dp[i-1] > 0 && s[i-dp[i-1]-1] == '('){
                    dp[i] = dp[i-1] + 2 + ((i-dp[i-1]-2)>=0?dp[i-dp[i-1]-2]:0);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < s.size(); i++)   {
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

