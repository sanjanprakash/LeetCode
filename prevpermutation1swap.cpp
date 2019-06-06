class Solution {
public:
    int firstOccurBS(vector<int> arr, int l, int r, int num) {
        int m = l + (r-l)/2;
        if (l < r) {
            if ((m == l || arr[m-1] < num) && arr[m] == num)
                return m;
            else if (arr[m] < num)
                return firstOccurBS(arr,m+1,r,num);
            else
                return firstOccurBS(arr,l,m-1,num);
        }
        return m;
    }
    
    int predBS(vector<int> arr, int leftmost, int l, int r, int num) {
        int m = l + (r-l)/2;
        if (l < r) {
            if (r == l+1) { 
                if (arr[l] < num)
                    return arr[r] < num ? r : l;
                return l-1;
            }
            if (arr[m] > num)
                return predBS(arr,leftmost,l,m-1,num);
            else
                return predBS(arr,leftmost,m+1,r,num);
        }
        return arr[m] != num ? m : firstOccurBS(arr,leftmost,m-1,arr[m-1]);
    }
    
    vector<int> prevPermOpt1(vector<int>& A) {
        int i;
        int temp, temp_id;
        vector<int>::iterator it;
        for (i = A.size()-1; i > 0; i--) {
            if (A[i] < A[i-1])
                break;
        }
        if (i > 0) {
            temp_id = predBS(A,i,i,A.size()-1,A[i-1]);
            temp = A[temp_id];
            A[temp_id] = A[i-1];
            A[i-1] = temp;
        }
        return A;
    }
};
