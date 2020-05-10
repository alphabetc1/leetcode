670. 最大交换.cpp
class Solution {
public:
    int maximumSwap(int num) {
        if(num <= 11)  return num;
        int t = 0, vis[10] = {}, bucket[10] = {};
        priority_queue<int>q;
        while(num) {
            t++;
            vis[t] = num % 10;
            q.push(vis[t]);
            if(!bucket[vis[t]]) {
                bucket[vis[t]] = t;
            }
            num /= 10;
        }
        for(int i = t; i > 0; i--) {
            if(vis[i] < q.top())  {
                int tmp = vis[i];
                vis[i] = vis[bucket[q.top()]];
                vis[bucket[q.top()]] = tmp;
                break;
            } 
            q.pop();
        }
        int res = 0;
        for(int i = t; i > 0; i--) {
            res *= 10;
            res += vis[i];
        }
        return res;
    }
};