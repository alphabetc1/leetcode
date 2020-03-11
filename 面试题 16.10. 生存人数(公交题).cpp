//方法1：逐年统计生存人数，对应的还有逐人统计生存年数
class Solution {
public:
	int maxAliveYear(vector<int>& birth, vector<int>& death) {
		int vis[110];
		memset(vis, 0, sizeof(vis));
		for (int i = 0; i < birth.size(); i++) {
			for (int j = birth[i]; j <= death[i]; j++)
				vis[j - 1900]++;
		}
		int count = 0, ans = 1900;
		for (int i = 0; i <= 100; i++) {
			if (vis[i] > count) {
				count = vis[i];
				ans = i + 1900;
			}
		}
		return ans;
	}
};

//解法2：排序后双指针归并
class Solution {
public:
	int maxAliveYear(vector<int>& birth, vector<int>& death) {
		sort(birth.begin(), birth.end());
		sort(death.begin(), death.end());
		int n = birth.size();
		int i = 0, j = 0, alive = 0, maxAlive = 0, ans = 0;
		while (i < n && j < n) {
			if (birth[i] <= death[j]) {
				alive++;
				i++;
				if (alive > maxAlive) {
					maxAlive = alive;
					ans = birth[i - 1];
				}
			}
			else {
				j++;
				alive--;
			}
		}
		return ans;
	}
};

//方法3：逐人+逐年统计年数
class Solution {
public:
	int maxAliveYear(vector<int>& birth, vector<int>& death) {
		int vis[110] = {};
		int n = birth.size();
		for (int i = 0; i < n; i++) {
			vis[birth[i] - 1900]++;
			vis[death[i] - 1900 + 1]--;
		}
		int ans = 0, maxAlive = 0, nowAlive = 0;
		for (int i = 0; i <= 100; i++) {
			nowAlive += vis[i];
			if (nowAlive > maxAlive) {
				maxAlive = nowAlive;
				ans = i + 1900;
			}
		}
		return ans;
	}
};