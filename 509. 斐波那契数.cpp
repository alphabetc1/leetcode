509. 斐波那契数.cpp

vector<vector<int>> MatMul(vector<vector<int>> &a, vector<vector<int>> &b)	{
	vector<vector<int>>c(2, vector<int>(2,0));
	c[0][0] = a[0][0]*b[0][0] + a[0][1] * b[1][0];
	c[0][1] = a[0][0]*b[0][1] + a[0][1] * b[1][1];
	c[1][0] = a[1][0]*b[0][0] + a[1][1] * b[1][0];
	c[1][1] = a[1][0]*b[0][1] + a[1][1] * b[1][1];
	return c;
}


vector<vector<int>> pow(vector<vector<int>> &a, int n)	{
	vector<vector<int>>b(2, vector<int>(2,1));
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
	vector<vector<int>>a(2, vector<int>(2,1));
	a[1][1] = 0;
	vector<vector<int>>b = pow(a, n);
	return b[0][0];
}