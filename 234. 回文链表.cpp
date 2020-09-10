234. 回文链表.cpp
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
    ListNode *listMid(ListNode *head)   {
        ListNode *fast = head, *slow = head;
        while(fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }

    ListNode *reverse(ListNode *head)   {
        ListNode *prev = nullptr;
        ListNode *cur = head;
        while(cur)  {
            ListNode *next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode *mid = listMid(head);
        ListNode *tmp = reverse(mid);
        while(tmp)  {
            if(tmp->val != head->val)   {
                return false;
            }
            tmp = tmp->next;
            head = head->next;
        }
        return true;
    }
};