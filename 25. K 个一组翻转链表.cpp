25. K 个一组翻转链表.cpp
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
    pair<ListNode*, ListNode*> reverseLink(ListNode* head, ListNode* tail)  {
        ListNode* pre = tail->next;
        ListNode* p = head;
        while(pre != tail)    {
            ListNode* tmp = p->next;
            p->next = pre;
            pre = p;
            p = tmp;
        }
        return {tail, head};
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(!head || !k) return head;
        ListNode* hair = new ListNode(-1);
        hair->next = head;
        ListNode* pre = hair;

        while(head) {
            ListNode *tail = pre;
            for(int i = 0; i < k; i++)  {
                tail = tail->next;
                if(!tail)   {
                    return hair->next;
                }
            }
            ListNode* tmp = tail->next;
            pair<ListNode*, ListNode*> ht = reverseLink(head, tail);
            
            pre->next = ht.first;
            ht.second->next = tmp;
            pre = ht.second;
            head = tmp;
        }
        return hair->next;
    }
};