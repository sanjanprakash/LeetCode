class Solution {
public:
    int fib(int N) {
        int i;
        int *arr = new int[N+1];
        for (i = 0; i < N+1; i++) {
            if (i < 2)
                arr[i] = i;
            else
                arr[i] = -1;
        }
        return helper(arr,N);
    }
    
    int helper(int *arr, int N) {
        if (arr[N] != -1)
            return arr[N];
        arr[N] = helper(arr,N-1) + helper(arr,N-2);
        return arr[N];
    }
};
