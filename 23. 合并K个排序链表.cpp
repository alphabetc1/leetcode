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

//基于归并排序
class Solution {
public:
    ListNode *merge(ListNode *p1, ListNode *p2) {
        ListNode *dummy = new ListNode(-1);
        ListNode *cur = dummy;
        while(p1 && p2) {
            if(p1->val < p2->val)   {
                cur->next = p1;
                p1 = p1->next;
            }else{
                cur->next = p2;
                p2 = p2->next;
            }
            cur = cur->next;
        }
        if(p1)  {
            cur->next = p1;
        }
        if(p2)  {
            cur->next = p2;
        }
        cur = dummy->next;
        delete dummy;
        return cur;
    }

    ListNode *mergeK(vector<ListNode*>& lists, int left, int right) {
        if(left == right)   {
            return lists[left];
        }else if(left > right)  {
            return nullptr;
        }
        int mid = ((right - left) >> 1) + left;
        return merge(mergeK(lists, left, mid), mergeK(lists, mid+1, right));
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(!n)  {
            return nullptr;
        }
        return mergeK(lists, 0, n-1);
    }
};