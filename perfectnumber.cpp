class Solution {
public:
    bool checkPerfectNumber(int num) {
        int i, n = sqrt(num);
        int sum = 0;
        for (i = 2; i <= n; i++) 
            sum = num%i ? sum : sum + i + (num/i);
        sum += 1;
        return (num != 1) && (sum == num);
    }
};
