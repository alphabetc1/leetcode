class Solution {
public:
    bool singleMatch(string value, int count)  {
        if(value.size() % count != 0)   return false;
        int gap = value.size() / count;
        for(int i = gap; i + gap <= value.size(); i += gap)   {
            if(value.substr(0, gap) != value.substr(i, gap))    return false;
        }
        return true;
    }

    bool doubleMatch(string pattern, string value, int len_a, int len_b)    {
        string tmp[2] = {"",""};
        for(int i = 0, j = 0; i < pattern.size(); ++i) {
            if(pattern[i] == 'a')   {
                if(tmp[0] == "")    {
                    tmp[0] = value.substr(j, len_a);
                }else{
                    if(value.substr(j, len_a) != tmp[0])  {
                        return false;
                    }
                }
                j += len_a;
            }else{
                if(tmp[1] == "")    {
                    tmp[1] = value.substr(j, len_b);
                }else{
                    if(value.substr(j, len_b) != tmp[1])    {
                        return false;
                    }
                }
                j += len_b;
            }
        }
        return true;
    }

    bool patternMatching(string pattern, string value) {
        if(pattern.empty()) {
            return value.empty();
        }
        else if(value.empty())   {
            int i = 1;
            for(; i < pattern.size() && pattern[i] == pattern[0]; ++i) ;
            return (i == pattern.size());
        }
        int cnt[2] = {};
        for(int i = 0; i < pattern.size(); ++i) {
            cnt[pattern[i] - 'a']++;
        }
        if(!cnt[0] || !cnt[1])  {
            return singleMatch(value, cnt[0] + cnt[1]);
        }
        for(int len_a = 0; len_a * cnt[0] <= value.size(); ++len_a) {
            if((value.size() - len_a*cnt[0]) % cnt[1] != 0) continue;
            int len_b = (value.size() - len_a*cnt[0]) / cnt[1];
            if(doubleMatch(pattern, value, len_a, len_b))   return true;
        }
        return false;
    }
};