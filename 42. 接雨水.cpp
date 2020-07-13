42. 接雨水.cpp
//dp
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>maxLeft(n, 0);
        vector<int>maxRight(n, 0);

        int now = 0;
        for(int i = 1; i < n; i++)  {
            maxLeft[i] = max(maxLeft[i-1], height[i-1]);
            maxRight[n-i-1] = max(maxRight[n-i], height[n-i]);
            now += height[i];
        }
        int sum = 0;
        for(int i = 1; i < n; i++)  {
            height[i] = max(height[i], min(maxLeft[i], maxRight[i]));
            sum += height[i];
        }
        return sum - now;
    }
};

//双指针
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, leftMax = 0, right = height.size()-1, rightMax = 0;
        int ans = 0;
        while(left < right) {
            if(height[left] < height[right])    {
                if(height[left] > leftMax)  {
                    leftMax = height[left];
                }else{
                    ans += leftMax - height[left];
                }
                left++;
            }else{
                if(height[right] > rightMax)  {
                    rightMax = height[right];
                }else{
                    ans += rightMax - height[right];
                }
                right--;
            }
        }
        return ans;
    }
};