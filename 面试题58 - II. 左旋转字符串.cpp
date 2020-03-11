#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#define NMAX 100010
using namespace std; 

class Solution {
public:
	string reverseLeftWords(string s, int n) {
		s.append(s.begin(), s.begin()+n);
		s.erase(0, n);
		return s;
	}
};