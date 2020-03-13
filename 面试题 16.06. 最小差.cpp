面试题 16.06. 最小差.cpp
//双指针求两数组之间最小差值
class Solution {
public:
    int smallestDifference(vector<int>& a, vector<int>& b) {
        int n = a.size(), m = b.size();
        if(!n || !m)    return 0;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long ans = INT_MAX;
        for(int i = 0, j = 0; i < n && j < m; ) {
            if(a[i] == b[j])    return 0;
            ans = min(ans, abs((long)a[i] - b[j]));
            if(a[i] < b[j]) i++;
            else j++;
        }
        return ans;
    }
};