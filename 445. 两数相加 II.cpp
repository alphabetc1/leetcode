445. 两数相加 II.cpp
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* ansHead = NULL;
        int count = 0;
        while(s1.size() || s2.size())   {
            int sum = count;
            if(!s1.empty())   {
                sum += s1.top();
                s1.pop();
            }
            if(!s2.empty())   {
                sum += s2.top();
                s2.pop();
            }
            count = sum / 10;
            sum %= 10;
            ListNode* newNode = new ListNode(sum);
            newNode->next = ansHead;
            ansHead = newNode;
        }
        if(count)   {
            ListNode* newNode = new ListNode(1);
            newNode->next = ansHead;
            ansHead = newNode;
        }
        return ansHead;
    }
};