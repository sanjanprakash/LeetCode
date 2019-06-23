class Solution {
public:
    bool isPerfectSquare(int num) {
        long long int l = 1, r = num-1, m;
        while (l <= r) {
            m = l + (r-l)/2;
            if (m*m == num)
                return true;
            if (m*m < num)
                l = m+1;
            else
                r = m-1;
        }
        return num == 1 ? true : false;
    }
};
