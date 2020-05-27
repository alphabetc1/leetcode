313. 超级丑数.cpp
class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<int> nums;
        nums.push_back(0);
        nums.push_back(1);
        vector<int> i_n(primes.size(), 1);
        int sum = 1;
        while(sum < n) {
            int temp = INT_MAX;
            for(int i = 0; i < primes.size(); i++)  {
                temp = min(temp, primes[i]*nums[i_n[i]]);
            }
            nums.push_back(temp);
            for(int i = 0; i < primes.size(); i++)  {
                while(primes[i] * nums[i_n[i]] <= temp)   {
                    i_n[i]++;
                }
            }
            sum++;
        }
        return nums[n];
    }
};