84. 柱状图中最大的矩形.cpp
/*
递增栈
每当从前向后扫描到一根柱子i，就把他之前所有比他高的柱子都算出最大面积
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int res = 0;
        heights.insert(heights.begin(), 0);
        heights.push_back(0);
        stack<int> s;
        for(int i = 0; i < heights.size(); i++) {
            while(!s.empty() && heights[s.top()] > heights[i])  {
                int h = heights[s.top()];
                s.pop();
                res = max(res, (i - s.top() - 1)*h);
            }
            s.push(i);
        }
        return res;
    }
};