#include <iostream>
#include <string>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * reverseList(ListNode* head) {
		if (!head || !head->next)	return head;
		ListNode *newHead = reverseList(head->next);
		head->next->next = head;
		head->next = NULL;
		return newHead;
	}
};


int main() {
	Solution s;
	ListNode *head = (ListNode*)malloc(sizeof(ListNode*));
	head = NULL;
	for (int i = 1; i < 4; i++) {
		ListNode *newHead = (ListNode*)malloc(sizeof(ListNode*));
		newHead->val = i;
		newHead->next = head;
		head = newHead;
	}
	cout << endl;
	head = s.reverseList(head);
	while (head) {
		cout << head->val << " ";
		head = head->next;
	}
	system("pause");
	return 0;
}