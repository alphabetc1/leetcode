92. 反转链表 II.cpp
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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *init = new ListNode(-1);
        init->next = head;
        ListNode *pre = init;
        for(int i = 0; i < m-1; i++)    {
            pre = pre->next;
        }
        head = pre->next;
        for(int i = m; i < n; i++)  {
            ListNode *tmp = head->next;
            head->next = tmp->next;
            tmp->next = pre->next;
            pre->next = tmp;
        }
        return init->next;
    }
};