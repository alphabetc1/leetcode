#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#define NMAX 100010
#define GAP  1000000007
using namespace std;
/*
dp[i][j][k]：k个单词的情况下，存在i个A且结尾是连续的j个L的字符串的数量
*/
class Solution {
public:
	int checkRecord(int n) {
		long dp[2][3][NMAX + 1];
		memset(dp, 0, sizeof(dp));
		dp[0][0][1] = 1;
		dp[0][1][1] = 1;
		dp[1][0][1] = 1;
		for (int i = 2; i <= n; i++) {
			dp[0][0][i] = (dp[0][0][i - 1] + dp[0][1][i - 1] + dp[0][2][i - 1])%GAP;
			dp[0][1][i] = dp[0][0][i - 1] % GAP;
			dp[0][2][i] = dp[0][1][i - 1] % GAP;
			dp[1][0][i] = (dp[0][0][i - 1] + dp[0][1][i - 1] + dp[0][2][i - 1] + dp[1][0][i-1] + dp[1][1][i - 1] + dp[1][2][i - 1]) % GAP;
			dp[1][1][i] = dp[1][0][i - 1] % GAP;
			dp[1][2][i] = dp[1][1][i - 1] % GAP;
		}
		int sum = (dp[0][0][n] + dp[0][1][n] + dp[0][2][n] + dp[1][0][n] + dp[1][1][n] + dp[1][2][n]) % GAP;
		return sum;
	}
};
