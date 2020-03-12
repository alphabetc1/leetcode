面试题06. 从尾到头打印链表.cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<int>ans;
    void getRev(ListNode* node) {
        if(!node)   return;
        getRev(node->next);
        ans.push_back(node->val);
    }
    vector<int> reversePrint(ListNode* head) {
        getRev(head);
        return ans;
    }
};