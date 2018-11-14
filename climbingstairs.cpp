class Solution {
public:
    int climbStairs(int n) {
        int *arr = new int[n+1];
        int i;
        arr[1] = 1;
        arr[2] = 2;
        for (i = 3; i <= n; i++) {
            arr[i] = arr[i-1] + arr[i-2];
        }
        return arr[n];
    }
};
