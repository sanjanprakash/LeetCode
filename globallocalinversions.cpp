class Solution {
public:
    void merge(vector<int>& A, int l, int m, int r, int &global) {
        int i, j = l;
        queue<int> left, right;
        for (i = l; i <= m; i++)
            left.push(A[i]);
        for (i = m+1; i <= r; i++)
            right.push(A[i]);
        while (!left.empty() && !right.empty()) {
            if (left.front() <= right.front()) {
                A[j] = left.front();
                left.pop();
            }
            else {
                global += left.size();
                A[j] = right.front();
                right.pop();
            }
            j++;
        }
        while (!left.empty()) {
            A[j] = left.front();
            left.pop();
            j++;
        }
        while (!right.empty()) {
            A[j] = right.front();
            right.pop();
            j++;
        }
    }
    
    void merge_sort(vector<int>& A, int l, int r, int &global) {
        int m;
        if (l < r) {
            m = l + (r-l)/2;
            merge_sort(A,l,m,global);
            merge_sort(A,m+1,r,global);
            merge(A,l,m,r,global);
        }
    }
    
    bool isIdealPermutation(vector<int>& A) {
        int i, n = A.size();
        int local = 0, global = 0;
        for (i = 0; i < n-1; i++) 
            local += A[i] > A[i+1];
        merge_sort(A,0,n-1,global);
        return local == global;
    }
};
