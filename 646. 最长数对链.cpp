646. 最长数对链.cpp
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size() <= 1)   return pairs.size();

        sort(pairs.begin(), pairs.end());
        int res = 1, lastRight = pairs[0][1];
        for(int i = 0; i < pairs.size(); i++)   {
            if(pairs[i][0] > lastRight) {
                res++;
                lastRight = pairs[i][1];
            }else if(pairs[i][1] < lastRight)   {
                lastRight = pairs[i][1];
            }
        }
        return res;
    }
};