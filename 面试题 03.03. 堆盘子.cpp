面试题 03.03. 堆盘子.cpp
class StackOfPlates {
public:
    int tag, num;
    vector<stack<int>> sSum;

    StackOfPlates(int cap) {
        tag = -1;
        num = cap;
    }   
    
    void push(int val) {
        if(tag < 0 || sSum[tag].size() == num) {
            stack<int>s;
            s.push(val);
            sSum.push_back(s);
            tag++;
        }else if(sSum[tag].size() < num)  {
            sSum[tag].push(val);
        }
    }
    
    int pop() {
        if(tag < 0 || !num)   return -1;
        int res = sSum[tag].top();  
        
        sSum[tag].pop();   
        if(!sSum[tag].size()) {
            tag--;
            sSum.pop_back();
        }
        return res;
    }
    
    int popAt(int index) {
        if(tag < 0 || index > tag || !num)  return -1;
        int res = sSum[index].top();
        sSum[index].pop();
        if(!sSum[index].size())   {
            for(int i = index; i < tag; i++)    {
                sSum[i] = sSum[i+1];
            }
            tag--;
            sSum.pop_back();
        }
        return res;
    }
};

/**
 * Your StackOfPlates object will be instantiated and called as such:
 * StackOfPlates* obj = new StackOfPlates(cap);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAt(index);
 */