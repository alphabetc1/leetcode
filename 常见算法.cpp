常见算法.cpp
//二分查找
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1, ans = nums.size();
        while(l <= r)    {
            int mid = ((r - l) >> 1) + l;
            if(nums[mid] == target) {
                return mid;
            }else if(nums[mid] < target)    {
                l = mid + 1;
            }else{
                ans = mid;
                r = mid - 1;
            }
        }
        return l;
    }
};

//二分求左侧边界
int searchInsert(vector<int>& nums, int target) {
    int left = 0, right = nums.size();
    while(left < right) {
        int mid = ((right - left)>>1) + left;
        if(nums[mid] < target)  {
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    return right;
}


//二分求右侧边界
int right_bound(int[] nums, int target) {
    int left = 0, right = nums.size();
    while(left < right) {
        int mid = ((right - left)>>1) + left;
        if(nums[mid] <= target)  {
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    return left - 1;
}

//面试题 17.14. 最小K个数.cpp
//快速排序
int Partition(vector<int> &nums, int low, int high)	{
	int pivot = nums[low];
	while(low < high)	{
		while(low < high && nums[high] >= pivot)	{
			high--;
		}
		nums[low] = nums[high];
		while(low < high && nums[low] <= pivot)	{
			low++;
		}
		nums[high] = nums[low];
	}
    nums[low] = pivot;
	return low;
}

void QuickSort(vector<int> &nums, int low, int high)	{
	if(low < high)	{
		int pivot = Partition(nums, low, high);
		QuickSort(nums, low, pivot-1);
		QuickSort(nums, pivot+1, high);
	}
}


//堆排序




//归并排序
class Solution {
public:
    vector<int> b;
    
    void merge(vector<int>& a, int left, int mid, int right)    {
        for(int i = left; i <= right; ++i)   {
            b[i] = a[i];
        }

        int lt = left, rt = mid + 1, k = left;
        while(lt <= mid && rt <= right) {
            if(b[lt] < b[rt])   {
                a[k++] = b[lt];
                ++lt;
            }else{
                a[k++] = b[rt];
                ++rt;
            }
        }

        while(lt <= mid)    {
            a[k++] = b[lt];
            ++lt;
        }

        while(rt <= right)   {
            a[k++] = b[rt];
            ++rt;
        }
    }

    void mergeSort(vector<int>& nums, int left, int right)   {
        if(left >= right)    {
            return;
        }
        
        int mid = ((right - left)>>1) + left;
        mergeSort(nums, left, mid);
        mergeSort(nums, mid + 1, right);
        merge(nums, left, mid, right);
    }

    vector<int> sortArray(vector<int>& nums) {
        b.resize(nums.size(), 0);
        mergeSort(nums, 0, nums.size() - 1);

        return nums;
    }
};

//反转链表——迭代
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *pre = nullptr;

        while(head) {
            ListNode *tmp = head->next;
            head->next = pre;
            pre = head;
            head = tmp;
        }
        return pre;
    }
};

//反转链表——递归
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr || head->next == nullptr)	return head;
        ListNode* newNode = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return newNode;
    }
};

//反转m到n
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

