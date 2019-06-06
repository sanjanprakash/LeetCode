class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
        int i;
        int non_grumpy = 0, grumpy_X = 0, max_grumpy = 0;
        for (i = 0; i < customers.size(); i++) {
            if (grumpy[i])
                grumpy_X += customers[i];
            else
                non_grumpy += customers[i];
            if (i >= X && grumpy[i-X])
                grumpy_X -= customers[i-X];
            if (max_grumpy < grumpy_X)
                max_grumpy = grumpy_X;
        }
        return non_grumpy + max_grumpy;
    }
};
