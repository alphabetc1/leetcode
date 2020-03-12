面试题 16.11. 跳水板.cpp
class Solution {
public:
    vector<int> divingBoard(int shorter, int longer, int k) {
        vector<int>ans;
        if(!k)  return ans;
        int num = k * shorter;
        ans.push_back(num);
        if(shorter == longer)   return ans;
        for(int i = 0; i < k; i++)  {
            num += longer - shorter;
            ans.push_back(num);
        }
        return ans;
    }
};