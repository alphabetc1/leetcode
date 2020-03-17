面试题09. 用两个栈实现队列.cpp
class CQueue {
public:
    stack<int> s1, s2;
    CQueue() {
        
    }
    
    void appendTail(int value) {
        s1.push(value);
    }
    
    int deleteHead() {
        if(s1.empty() && s2.empty())    return -1;
        else if(s2.empty())    {
            while(!s1.empty())  {
                s2.push(s1.top());
                s1.pop();
            }
        }
        int tmp = s2.top();
        s2.pop();
        return tmp;
    }
};