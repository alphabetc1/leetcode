剑指 Offer 10- I. 斐波那契数列.cpp
class Solution {
public:
    vector<vector<unsigned long long>> MatMul(vector<vector<unsigned long long>> &a, vector<vector<unsigned long long>> &b)	{
	    vector<vector<unsigned long long>>c(2, vector<unsigned long long>(2,0));
	    c[0][0] = (a[0][0]*b[0][0] + a[0][1] * b[1][0]) % 1000000007;
	    c[0][1] = (a[0][0]*b[0][1] + a[0][1] * b[1][1]) % 1000000007;
	    c[1][0] = (a[1][0]*b[0][0] + a[1][1] * b[1][0]) % 1000000007;
	    c[1][1] = (a[1][0]*b[0][1] + a[1][1] * b[1][1]) % 1000000007;
	    return c;
    }

    vector<vector<unsigned long long>> pow(vector<vector<unsigned long long>> &a, int n)	{
	    vector<vector<unsigned long long>>b(2, vector<unsigned long long>(2,1));
	    while(n)	{
		    if(n & 1)	{
			    b = MatMul(b,a);
		    }
		    a = MatMul(a,a);
		    n >>= 1;
        }
	    return b;
    }

    int fib(int n)	{
        if(!n)  return 0;
        else if(1 == n) return 1;
	    vector<vector<unsigned long long>>a(2, vector<unsigned long long>(2,1));
	    a[1][1] = 0;
	    vector<vector<unsigned long long>>b = pow(a, n-2);
	    return (int)b[0][0];
    }
};