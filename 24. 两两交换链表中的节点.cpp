24. 两两交换链表中的节点.cpp

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL || head->next == NULL)    return head;
        ListNode* next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};