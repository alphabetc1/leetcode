142. 环形链表 II.cpp
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
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr) {
            return nullptr;
        }

        ListNode *first = head, *second = head;
        
        while(first != nullptr && first->next != nullptr)  {
            first = first->next->next;
            second = second->next;
            if(first == second) {
                break;
            }
        }

        if(first == nullptr || first->next == nullptr)    {
            return nullptr;
        }
        
        ListNode *tmp = head;
        while(tmp != first) {
            tmp = tmp->next;
            first = first->next;
        }
        return first;
    }
};