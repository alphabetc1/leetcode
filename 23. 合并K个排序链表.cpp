23. 合并K个排序链表.cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
先前版本，无尽丑陋
*/
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(!n)  return NULL;
        else if(1 == n) return lists[0];
        vector<int>index(n,1);
        int minNum, minTag, count = 0;
        ListNode* head = new ListNode(0);
        ListNode* now = head;
        ListNode* nowNode;
        for(int i = 0; i < n; i++)     {
            if(!lists[i])   count++;
        }
        while(count < n )    {
            minNum = 0x3f3f3f3f;
            for(int i = 0; i < n; i++)  {
                nowNode = lists[i];
                if(!nowNode) {
                    continue;
                }
                if(nowNode->val < minNum) {
                    minNum = nowNode->val;
                    minTag = i;
                }
            }
            if(count == n)  break;
            ListNode* newNode = new ListNode(minNum);
            now->next = newNode;
            now = now->next;
            lists[minTag] = lists[minTag]->next;
            if(!lists[minTag])  count++;
        }
        return head->next;
    }
};

/*
优先级队列优化后
*/
class Solution {
public:
    struct cmp{
        bool operator() (ListNode* a, ListNode* b) {
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, cmp> heapQ;
        int n = lists.size();
        for(int i = 0; i < n; i++)  {
            if(lists[i])  heapQ.push(lists[i]);
        }
        ListNode* pHead = new ListNode(-1);
        ListNode* pCur = pHead;
        while(!heapQ.empty())   {
            ListNode* top = heapQ.top(); heapQ.pop();
            pCur->next = top;
            pCur = pCur->next;
            if(top->next)   {
                heapQ.push(top->next);
            }
        }
        return pHead->next;
    }
};