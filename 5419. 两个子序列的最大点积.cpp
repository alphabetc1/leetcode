5419. 两个子序列的最大点积.cpp
//dp,maxNum保证序列长度至少为1（在没人点积大于0时选择一个最大点积）
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> dp(nums1.size()+1, vector<int>(nums2.size()+1, 0));
        int maxNum = nums1[0] * nums2[0];
        for(int i = 1; i <= nums1.size(); i++)   {
            for(int j = 1; j <= nums2.size(); j++)   {
                dp[i][j] = max(max(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1] + nums1[i-1] * nums2[j-1]);
                maxNum = max(maxNum, nums1[i-1] * nums2[j-1]);
            }
        }
        return maxNum > 0?dp[nums1.size()][nums2.size()]:maxNum;
    }
};

//下面这样写更好理解
class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int sz1=nums1.size(),sz2=nums2.size();
        vector<vector<int>> dp(sz1+1,vector<int>(sz2+1,-1e8));

        for(int i=1;i<=sz1;i++){
            for(int j=1;j<=sz2;j++){
                //1.1
                dp[i][j]=nums1[i-1]*nums2[j-1];
                //1.2
                dp[i][j]=max(dp[i][j],dp[i][j]+dp[i-1][j-1]);
                //2
                dp[i][j]=max(dp[i][j],dp[i][j-1]);
                //3
                dp[i][j]=max(dp[i][j],dp[i-1][j]);
                //4
                dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
            }
        }
        return dp[sz1][sz2];
    }
};
