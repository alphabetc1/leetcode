class Solution {
public:
	bool canThreePartsEqualSum(vector<int>& A) {
		int sum = 0;
		for (int i = 0; i < A.size(); i++) {
			sum += A[i];
		}
		if (sum % 3 != 0)    return false;
		int now = 0, count = 0, gap = sum / 3;
		for (int i = 0; i < A.size() - 1; i++) {
			now += A[i];
			//cout<<now<<endl;
			if (now == gap && count != 2) {
				now = 0;
				count++;
			}
		}
		now += A[A.size() - 1];
		if (now == gap)  count++;
		if (count != 3)  return false;
		return true;
	}
};