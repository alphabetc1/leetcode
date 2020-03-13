面试题 17.20. 连续中值.cpp
//对顶堆
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, less<int>> q1;
    priority_queue<int, vector<int>, greater<int>> q2;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(q1.empty() || num < q1.top())  q1.push(num);
        else q2.push(num);
        if(q1.size() > q2.size() + 1)  {
            q2.push(q1.top());
            q1.pop();
        }
        else if(q2.size() > q1.size())  {
            q1.push(q2.top());
            q2.pop();
        }
    }
    
    double findMedian() {
        if(q1.size() != q2.size())  return (double)q1.top();
        else{
            return ((double)q1.top() + (double)q2.top())/2;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */