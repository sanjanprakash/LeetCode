class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        int *arr = new int[n+1];
        int i, count_dig = 9,count = 9;
        arr[0] = 1;
        arr[1] = 10;
        for (i = 2; i <= n; i++) {
            if (n >= 10)
                arr[i] = arr[i-1];
            else {
                count_dig *= count;
                arr[i] = count_dig + arr[i-1];
                count--;                
            }
        }
        return arr[n];
    }
};
