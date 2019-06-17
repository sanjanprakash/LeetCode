class Solution {
public:
    int sumOfDigits(vector<int>& A) {
        int i, min = INT_MAX, sum = 0;
        for (i = 0; i < A.size(); i++) {
            if (A[i] < min)
                min = A[i];        
        }
        while (min > 0) {
            sum += min%10;
            min /= 10;
        }
        return sum%2 == 0;
    }
};
