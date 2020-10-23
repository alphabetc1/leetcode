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
    ListNode *cut(ListNode *head, int length)   {
        auto p = head;
        while(--length && p)    {
            p = p->next;
        }
        if(!p)  {
            return nullptr;
        }
        auto next = p->next;
        p->next = nullptr;
        return next;
    }

    ListNode *merge(ListNode *h1, ListNode *h2) {
        ListNode dummyHead(0);
        auto p = &dummyHead;
        auto p1 = h1, p2 = h2;
        while(p1 && p2) {
            if(p1->val < p2->val)   {
                p->next = p1;
                p1 = p1->next;
                p = p->next;
            }else{
                p->next = p2;
                p2 = p2->next;
                p = p->next;
            }
        }
        p->next = p1?p1:p2;
        return dummyHead.next;
    }

    ListNode* sortList(ListNode* head) {
        ListNode dummyHead(0);
        dummyHead.next = head;
        auto p = head;
        int length = 0;
        while(p)    {
            length++;
            p = p->next;
        }
        for(int size = 1; size < length; size <<= 1)    {
            auto cur = dummyHead.next;
            auto tail = &dummyHead;
            while(cur)  {
                auto left = cur;
                auto right = cut(left, size);
                cur = cut(right, size);

                tail->next = merge(left, right);
                while(tail->next) {
                    tail = tail->next;
                }
            }
        }
        return dummyHead.next;
    }
};