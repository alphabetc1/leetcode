1014. 最佳观光组合.cpp
//DP O(n)
//max(A[i]+i+A[j]-j)
class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int left = A[0], res = INT_MIN;
        for(int i = 1; i < A.size(); i++)   {
            res = max(res, left+A[i]-i);
            left = max(left, A[i]+i);
        }
        return res;
    }
};

//分治做法 O(nlogn)
class Solution {
public:
    int mergeFind(vector<int>& A, int st, int ed)   {
        if(st == ed - 2)    return A[st]+A[ed-1]-1;
        else if(st < ed - 2) {
            int mid = (st + ed) / 2;
            int leftSum = mergeFind(A, st, mid);
            int rightSum = mergeFind(A, mid, ed);

            int midLeft = A[mid], midRight = A[mid+1];
            int leftTag = mid, rightTag = mid+1;
            int t = 1;
            for(int i = mid-1; i >= st; i--)    {
                if(A[i]>midLeft+t)  {
                    midLeft = A[i];
                    leftTag = i;
                    t = 1;
                }else{
                    t++;
                }
            }
            t = 1;
            for(int i = mid+2; i < ed; i++)    {
                if(A[i]>midRight+t)  {
                    midRight = A[i];
                    rightTag = i;
                    t = 1;
                }else{
                    t++;
                }
            }
            int midSum = midLeft+midRight+leftTag-rightTag;
            leftTag = mid-1;
            rightTag = mid;
            midLeft = A[mid-1], midRight = A[mid];
            t = 1;
            for(int i = mid-2; i >= st; i--)    {
                if(A[i]>midLeft+t)  {
                    midLeft = A[i];
                    leftTag = i;
                    t = 1;
                }else{
                    t++;
                }
            }
            t = 1;
            for(int i = mid+1; i < ed; i++)    {
                if(A[i]>midRight+t)  {
                    midRight = A[i];
                    rightTag = i;
                    t = 1;
                }else{
                    t++;
                }
            }
            midSum = max(midSum, midLeft+midRight+leftTag-rightTag);
            
            return max(midSum, max(leftSum, rightSum));
        }
        return 0;
    }

    int maxScoreSightseeingPair(vector<int>& A) {
        int res = mergeFind(A, 0, A.size());
        return res;
    }
};