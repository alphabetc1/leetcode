673. 最长递增子序列的个数.cpp
/*
**方法一：双DP
**dp[i]表示以第i个数为结尾的最长递增序列长度
**cnt[i]表示以第i个数为结尾的最长递增序列数量
*/
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        if(nums.size() <= 1)    return nums.size();

        int maxLength = 0, res = 0;
        vector<int> dp(nums.size(), 1);
        vector<int> cnt(nums.size(), 1);
        for(int i = 0; i < nums.size(); i++)    {
            for(int j = 0; j < i; j++)    {
                if(nums[i] > nums[j])   {
                    if(dp[j] + 1 > dp[i])   {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];
                    }else if(dp[j]+1 == dp[i])  {
                        cnt[i] += cnt[j];
                    }
                }
            }
            if(dp[i] > maxLength)   {
                maxLength = dp[i];
                res = cnt[i];
            }else if(maxLength == dp[i])    {
                res += cnt[i];
            }
        }
        return res;
    }
};

/*
**方法二：线段树
*/
class Solution
{
    class Node
    {
    public:
        int maxlength, cnt;
        Node()
        {
            maxlength = 1;
            cnt = 0;
        }
        // 区间合并法则
        // override: +=
        Node operator+=(Node &b)
        {
            if (b.maxlength == this->maxlength)
            {
                this->cnt += b.cnt;
            }
            else if (b.maxlength > this->maxlength)
            {
                this->maxlength = b.maxlength;
                this->cnt = b.cnt;
            }
            return *this;
        }
    };

    int lowbit(int x)
    {
        return x & (-x);
    }

    // 更新一个点后向上更新
    void add(Node nodes[], int rank, Node now, int size)
    {
        for (; rank <= size; rank += lowbit(rank))
        {
            nodes[rank] += now;
        }
    }

    // 单点查找
    Node query(Node nodes[], int rank)
    {
        Node res;
        while (rank)
        {
            res += nodes[rank];
            rank -= lowbit(rank);
        }
        return res;
    }

public:
    int findNumberOfLIS(vector<int> &nums)
    {
        if (nums.size() <= 1)
        {
            return nums.size();
        }
        vector<int> sortnums(nums);
        sort(sortnums.begin(), sortnums.end());
        Node nodes[nums.size() + 1] = {Node()};
        Node ans = Node();
        // 按nums[]顺序遍历，保证j<i这个条件,同时又用二分查找找出当前数num的下界nums[rank]
        // 以nums[rank]结尾的LIS是最长的（之一）,长度为lmax
        // 长度为lmax的LIS个数已经在树状数组中，查询后可得到
        // 把当前数num加到树状数组里面
        for (auto num : nums)
        {
            // 二分搜索当前数的下界排名
            int rank = lower_bound(sortnums.begin(), sortnums.end(), num) - sortnums.begin();
            Node now = query(nodes, rank);
            now.maxlength++;
            now.cnt = max(now.cnt, 1);
            ans += now;
            add(nodes, rank + 1, now, nums.size());
        }
        return ans.cnt;
    }
};
