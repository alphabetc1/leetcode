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

//左侧边界二分
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while(l < r)    {
            int mid = l + ((r - l) >> 1);
            if(nums[mid] >= target) {
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
    }
};

//右侧边界二分
int right_bound(int[] nums, int target) {
    if (nums.length == 0) return -1;
    int left = 0, right = nums.length;

    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] == target) {
            left = mid + 1; // 注意
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else if (nums[mid] > target) {
            right = mid;
        }
    }
    return left - 1; // 
}


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
void AdjustUp(vector<int> &nums, int k)	{
	nums[0] = nums[k];
	int i = k / 2;
	while(i > 0 && nums[i] < nums[0])	{
		A[k] = A[i];
		k = i;
		i = k / 2;
	}
	nums[k] = nums[0];
}

void AdjustDown(vector<int> &nums, int k, int len)	{
	nums[0] = nums[k];
	for(int i = 2 * k; i <= len; i *= 2)	{
		if(i < len && nums[i] < nums[i+1])	{
			i++;
		}
		if(nums[0] >= nums[i])	{
			break;
		}else	{
			nums[k] = nums[i];
			k = i;
		}
	}
	nums[k] = nums[0];
}

void BuildMaxHeap(std::vector<int> &nums, int len)	{
	for(int i = len /2 ; i > 0; i--)	{
		AdjustDown(v, i, len);
	}
}

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

