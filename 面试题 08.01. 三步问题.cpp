面试题 08.01. 三步问题.cpp
class Solution {
public:
    int mod = 1000000007;
    vector<vector<unsigned long long>> matMul(vector<vector<unsigned long long>> &A, vector<vector<unsigned long long>> &B)    {
        vector<vector<unsigned long long>> C(3, vector<unsigned long long> (3));

        C[0][0] = ((A[0][0] * B[0][0]) % mod + (A[0][1] * B[1][0]) % mod + (A[0][2] * B[2][0]) % mod) % mod;
        C[0][1] = ((A[0][0] * B[0][1]) % mod + (A[0][1] * B[1][1]) % mod + (A[0][2] * B[2][1]) % mod) % mod;
        C[0][2] = ((A[0][0] * B[0][2]) % mod + (A[0][1] * B[1][2]) % mod + (A[0][2] * B[2][2]) % mod) % mod;

        C[1][0] = ((A[1][0] * B[0][0]) % mod + (A[1][1] * B[1][0]) % mod + (A[1][2] * B[2][0]) % mod) % mod;
        C[1][1] = ((A[1][0] * B[0][1]) % mod + (A[1][1] * B[1][1]) % mod + (A[1][2] * B[2][1]) % mod) % mod;
        C[1][2] = ((A[1][0] * B[0][2]) % mod + (A[1][1] * B[1][2]) % mod + (A[1][2] * B[2][2]) % mod) % mod;

        C[2][0] = ((A[2][0] * B[0][0]) % mod + (A[2][1] * B[1][0]) % mod + (A[2][2] * B[2][0]) % mod) % mod;
        C[2][1] = ((A[2][0] * B[0][1]) % mod + (A[2][1] * B[1][1]) % mod + (A[2][2] * B[2][1]) % mod) % mod;
        C[2][2] = ((A[2][0] * B[0][2]) % mod + (A[2][1] * B[1][2]) % mod + (A[2][2] * B[2][2]) % mod) % mod;

        return C;
    }

    vector<vector<unsigned long long>> pow(vector<vector<unsigned long long>> base, int n)    {
        vector<vector<unsigned long long>> ans(3, vector<unsigned long long> (3,0));
        ans[0][0] = 4;
        ans[0][1] = 2;
        ans[0][2] = 1;
        while(n)    {
            if(n & 1)   {
                ans = matMul(ans, base);
            }
            base = matMul(base, base);
            n >>= 1;
        }
        return ans;
    }

    int waysToStep(int n) {
       if(!n)   {
           return 0;
       }else if(1 == n) {
           return 1;
       }else if(2 == n) {
           return 2;
       }else if(3 == n) {
           return 4;
       }
       vector<vector<unsigned long long>> base(3, vector<unsigned long long> (3,0));
       base[0][0] = base[0][1] = base[1][0] = base[1][2] = base[2][0] = 1;
       vector<vector<unsigned long long>> ans = pow(base, n - 3);
       return (int)ans[0][0];
    }
};