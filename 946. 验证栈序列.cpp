946. 验证栈序列.cpp
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> s;
        int j = 0;
        for(int i = 0; i < pushed.size(); i++)  {
            s.push(pushed[i]);
            while(!s.empty() && s.top() == popped[j]) {
                s.pop();
                j++;
            }
        }
        while(!s.empty() && j < popped.size())  {
            if(s.top() == popped[j])    {
                s.pop();
                j++;
            }else{
                return false;
            }
        }
        return true;
    }
};