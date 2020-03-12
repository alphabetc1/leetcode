面试题 16.07. 最大数值.cpp
class Solution {
public:
    int maximum(int a, int b) {
        uint64_t dif =(uint64_t) a - (uint64_t)b; 
        int k = dif>>63;
        return a*(k^1) + b*k;
    }
};