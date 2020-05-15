class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        int n = A.size();
        int neg_max = INT_MIN, pos_max = INT_MIN;
        int total_sum = 0, neg_sum = 0, pos_sum = 0;
        for (int &x : A) {
            total_sum += x;
            neg_sum += -x;
            pos_sum += x;
            neg_max = max(neg_sum, neg_max);
            pos_max = max(pos_sum, pos_max);
            neg_sum = max(0, neg_sum);
            pos_sum = max(0, pos_sum);
        }
        neg_max = (total_sum + neg_max == 0) ? INT_MIN : total_sum + neg_max;
        return max(neg_max, pos_max);
    }
};
