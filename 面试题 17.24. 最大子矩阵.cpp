class Solution {
public:
	vector<int> getMaxMatrix(vector<vector<int>>& matrix) {
		vector<int> ans = {0,0,0,0};
        if(!matrix.size() || !matrix[0].size()) {
            return ans;
        }
        int n = matrix.size(), m = matrix[0].size();

        int maxSum = 0x80000000;
        
        for(int i = 0; i < n; ++i)  {
            vector<int> maxLen(m);
            for(int j = i; j < n; ++j)  {
                for(int k = 0; k < m; ++k)  {
                    maxLen[k] += matrix[j][k];
                }

                int cnt = 0, st, ed;
                for(int k = 0; k < m; ++k)  {
                    if(cnt <= 0)    {
                        cnt = maxLen[k];
                        st = k;
                    }else{
                        cnt += maxLen[k];
                    }

                    if(cnt > maxSum)    {
                        maxSum = cnt;
                        ed = k;
                        ans[0] = i;
                        ans[1] = st;
                        ans[2] = j;
                        ans[3] = ed;
                    }
                }
            }
        }

        return ans;
	}
};