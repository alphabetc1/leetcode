179. 最大数.cpp
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        if(all_of(nums.begin(), nums.end(), [](int x)  {return x == 0;}))   {
            return "0";
        }
        vector<string> strVec(nums.size());
        for(int i = 0; i < nums.size(); ++i)  {
            strVec[i] = to_string(nums[i]);
        }
        sort(strVec.begin(), strVec.end(), [](const string &s1, const string &s2)   {
            return s1 + s2 > s2 + s1;
        });
        
        return accumulate(strVec.begin(),strVec.end(), string());
    }
};