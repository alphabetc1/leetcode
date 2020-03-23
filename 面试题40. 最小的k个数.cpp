面试题40. 最小的k个数.cpp
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        priority_queue<int>q;
        vector<int> ans;
        if(!k)  return ans;
        for(auto num:arr)   {
            if(q.size() < k)    {
                q.push(num);
            }else{
                if(num < q.top()) {
                    q.pop();
                    q.push(num);
                }
            }
        }
        while(!q.empty())   {
            ans.push_back(q.top());
            q.pop();
        }
        return ans;
    }
};