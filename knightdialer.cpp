class Solution {
public:
    void Counter(int *arr) {
        int *temp = new int[10];
        int i;
        temp[0] = (arr[4] + arr[6]) % 1000000007;
        temp[1] = (arr[6] + arr[8]) % 1000000007;
        temp[2] = (arr[7] + arr[9]) % 1000000007;
        temp[3] = (arr[4] + arr[8]) % 1000000007;
        temp[4] = (((arr[0] + arr[3]) % 1000000007) + arr[9]) % 1000000007;
        temp[5] = 0;
        temp[6] = (((arr[0] + arr[1]) % 1000000007) + arr[7]) % 1000000007;
        temp[7] = (arr[2] + arr[6]) % 1000000007;
        temp[8] = (arr[1] + arr[3]) % 1000000007;
        temp[9] = (arr[2] + arr[4]) % 1000000007;
        for (i = 0; i < 10; i++)
            arr[i] = temp[i];
    }
    int knightDialer(int N) {
        int *arr = new int[10];
        int *occ = new int[10];
        if (N <= 2)
            return N*10;
        int i,j;
        int ans = 0;
        for (i = 0; i < 10; i++) {
            arr[i] = 1;
            occ[i] = 2;
            if (i == 4 || i == 6)
                occ[i] = 3;
            if (i == 5)
                occ[i] = 0;
        }
        for (i = 1; i < N-1; i++)
            Counter(arr);
        for (i = 0; i < 10; i++) {
            for (j = 0; j < occ[i]; j++)
                ans = (ans + arr[i]) % 1000000007;
        }
        return ans;
    }
};
