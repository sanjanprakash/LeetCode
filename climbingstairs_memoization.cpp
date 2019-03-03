class Solution {
public:
    int climbStairs(int n) {
        int i;
        int *arr = new int[n+1];
        for (i = 0; i < n+1; i++) {
            if (i < 3)
                arr[i] = i;
            else
                arr[i] = -1;
        }
        return helper(arr,n);
    }
    
    int helper(int *arr, int n) {
        if (arr[n] != -1)
            return arr[n];
        arr[n] = helper(arr,n-1) + helper(arr,n-2);
        return arr[n];
    }
};
