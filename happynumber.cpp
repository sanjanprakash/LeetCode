class Solution {
public:
    bool isHappy(int n) {
        int sum;
        unordered_map<int,bool> check;
        while (1) {
            check[n] = true;
            sum = 0;
            while (n > 0) {
                sum += (n%10) * (n%10);
                n /= 10;
            }
            if (sum == 1)
                return true;
            n = sum;
            if (check[n] == true)
                break;
        }
        return false;
    }
};
