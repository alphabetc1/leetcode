155. 最小栈.cpp
class MinStack {
    stack<int> s, minStack;
public:
    /** initialize your data structure here. */
    MinStack() {
        minStack.push(INT_MAX);
    }
    
    void push(int x) {
        s.push(x);
        minStack.push(min(x, minStack.top()));
    }
    
    void pop() {
        s.pop();
        minStack.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */