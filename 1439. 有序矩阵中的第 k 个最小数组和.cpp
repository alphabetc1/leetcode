1439. 有序矩阵中的第 k 个最小数组和.cpp
//multiset暴力法
class Solution {
public:
    int kthSmallest(vector<vector<int>>& mat, int k) {
        int m = mat.size(), n = mat[0].size();
        multiset<int>s(mat[0].begin(), mat[0].end());
        for(int i = 1; i < m; i++)  {
            multiset<int>temp;
            for(int x : s)  {
                for(int y : mat[i])  {
                    temp.insert(x + y);
                }
            }
            s.clear();
            auto it = temp.begin();
            for(int j = 0; j < min(k, (int)temp.size()); j++, it++)  {
                s.insert(*it);
            }
        }
        return *s.rbegin();
    }
};

//二分查找
class Solution {
public:
    vector<vector<int>> temp;
    int m, n;
    int kthSmallest(vector<vector<int>>& mat, int k) {
        temp = mat;
        m = mat.size(), n = mat[0].size();
        int left = 0, right = 0;
        for(int i = 0; i < m; i++) {
            left += mat[i][0], right += mat[i].back();
        }
        int sum = left;
        while(left < right) {
            int mid = (left + right) >> 1;
            int num = 1;
            dfs(mid, 0, sum, num, k);
            if(num >= k)    {
                right = mid;
            }else{
                left = mid + 1;
            }
        }
        return left;
    }

    void dfs(int mid, int index, int sum, int &num, int k)    {
        if(sum > mid || index == m || num > k)  return;
        dfs(mid, index + 1, sum, num, k);
        for(int i = 1; i < n; i++)  {
            if(sum + temp[index][i] - temp[index][0] <= mid) {
                num++;
                dfs(mid, index + 1, sum + temp[index][i] - temp[index][0], num, k);
            }else{
                break;
            }
        }
    }
};

