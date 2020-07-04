class Solution {
public:
    int nthUglyNumber(int n) {
        int i, l1 = 0, l2 = 0, l3 = 0;
        int next;
        vector<int> uglyNums(n, 1);
        for (i = 1; i < n; i++) {
            next = min(2*uglyNums[l1], min(3*uglyNums[l2], 5*uglyNums[l3]));
            if (next == 2*uglyNums[l1])
                l1++;
            if (next == 3*uglyNums[l2])
                l2++;
            if (next == 5*uglyNums[l3])
                l3++;
            uglyNums[i] = next;
        }
        return uglyNums[n-1];
    }
};
