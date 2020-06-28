239. 滑动窗口最大值.cpp
//双端队列法
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        deque<int>q;
        
        for(int i = 0; i < nums.size() && i < k; i++)  {
            while(!q.empty() && nums[q.back()] < nums[i])   {
                q.pop_back();
            }
            q.push_back(i);
        }

        res.push_back(nums[q.front()]);

        for(int i = k; i < nums.size(); i++)    {
            while(!q.empty() && q.front() <= i - k) {
                q.pop_front();
            }
            while(!q.empty() && nums[q.back()] < nums[i])   {
                q.pop_back();
            }
            q.push_back(i);
            res.push_back(nums[q.front()]);
        }
        return res;
    }
};

//dp
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int>res;
        vector<int>left(nums);
        vector<int>right(nums);
        
        for(int i = 1; i < nums.size(); i++)    {
            if(i % k)  {
                left[i] = max(left[i-1], nums[i]);
            }else{
                left[i] = nums[i];
            }

            int j = nums.size() - i - 1;

            if((j+1) % k) {
                right[nums.size() - i - 1] = max(right[nums.size() - i], nums[nums.size() - i - 1]);
            }else{
                right[nums.size() - i - 1] = nums[nums.size() - i - 1];
            }
        }
        

        for(int i = k-1; i < nums.size(); i++)  {
            res.push_back(max(left[i], right[i - k + 1]));
        }
        return res;
    }
};