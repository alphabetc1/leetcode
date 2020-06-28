面试题 17.08. 马戏团人塔.cpp
class Solution {
public:
    int FindPos(vector<int>& tmp, int target)  {
        int start = 0, end = tmp.size();
        while(start <= end) {
            int mid = (start + end) >> 1;
            if(tmp[mid] == target)  {
                return mid;
            }else if(tmp[mid] < target) {
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return start;
    }

    int bestSeqAtIndex(vector<int>& height, vector<int>& weight) {
        if(!height.size())  return 0;
        vector<pair<int, int>> dp(height.size(), make_pair(0,0));
        for(int i = 0; i < height.size(); i++)  {
            dp[i].first = height[i];
            dp[i].second = weight[i];
        }
        sort(dp.begin(), dp.end(), [](pair<int, int> a, pair<int, int> b)   {
            if(a.first < b.first) return true;
            else if(a.first == b.first) return a.second > b.second;
            return false;
        });
        vector<int>tmp;
        tmp.push_back(dp[0].second);
        for(int i = 0; i < dp.size(); i++)  {
            if(dp[i].second > tmp.back())   {
                tmp.push_back(dp[i].second);
            }else{
            	//auto pos = lower_bound(tmp.begin(), tmp.end(), dp[i].second);
            	//*pos = dp[i].second;
                int pos = FindPos(tmp, dp[i].second);	//二分查找插入位置，也可以用lower_bound
                tmp[pos] = dp[i].second;
            }
        }
        return tmp.size();
    }
};

                