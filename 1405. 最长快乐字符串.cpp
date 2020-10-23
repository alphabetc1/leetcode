1405. 最长快乐字符串.cpp
class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        vector<pair<int, char>> v(3);
        v[0].first = a, v[0].second = 'a';
        v[1].first = b, v[1].second = 'b';
        v[2].first = c, v[2].second = 'c';
        sort(v.begin(), v.end());
        
        string ans;
        while(v[0].first)   {
            ans = ans + v[0].second + v[1].second + v[2].second;
            v[0].first--;
            v[1].first--;
            v[2].first--;
        }
        while(v[1].first)   {
            ans = ans + v[1].second + v[2].second;
            v[1].first--;
            v[2].first--;
        }
        int i = 0;
        while(i < ans.size() && v[2].first)   {
            if(ans[i] != v[2].second)   {
                ans.insert(i, v[2].first == 1?1:2, v[2].second);
                v[2].first = (v[2].first == 1?0:v[2].first-2);
            }else if(ans[i] == v[2].second && ans[i+1] != v[2].second)  {
                ans.insert(i, 1, v[2].second);
                v[2].first--;
            }
            i += 3;
        }
        return ans;
    }
};