面试题59 - II. 队列的最大值.cpp
class MaxQueue {
public:
    queue<int> q1;
    deque<int> q2;

    MaxQueue() {

    }
    
    int max_value() {
        if(!q2.size())  return -1;
        else return q2.front();
    }
    
    void push_back(int value) {
        q1.push(value);
        
        while(q2.size() && q2.back() < value)    {
            q2.pop_back();
        }
        q2.push_back(value);
    }
    
    int pop_front() {
        if(!q1.size())  return -1;
        int res = q1.front();
        
        if(q2.front() == q1.front())   {
            q2.pop_front();
        }
        q1.pop();
        
        return res;
    }
};

/**
 * Your MaxQueue object will be instantiated and called as such:
 * MaxQueue* obj = new MaxQueue();
 * int param_1 = obj->max_value();
 * obj->push_back(value);
 * int param_3 = obj->pop_front();
 */