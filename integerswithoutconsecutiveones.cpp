class Solution {
public:
    int fibonacci(int n) {
        int i = 2;
        vector<int> dp(n+2,1);
        while (i < n+2) {
            dp[i] = dp[i-1] + dp[i-2];
            i++;
        }
        return dp[n+1];
    }
    
    int findIntegers(int num) {
        int nbits = 1, temp = num;
        int j = 0, div = 1;
        if (num <= 3)
            return num/2+2;
        else {
            while (temp != 1) {
                temp /= 2;
                nbits++;
            }
            while (j < nbits-2) {
                div *= 2;
                j++;
            }
            if (num/div == 3)
                return fibonacci(nbits);
            return num-2*div ? fibonacci(nbits-1) + findIntegers(num-2*div) : fibonacci(nbits-1)+1;
        }
    }
};
