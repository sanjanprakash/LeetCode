class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int i,j,l;
        int r = matrix.size(), c;
        int ans = INT_MIN, cur_max, cur_sum;
        set<int> dict;
        if (r) {
            c = matrix[0].size();
            for (i = 0; i < c; i++) {
                vector<int> run_sum(r,0);
                for (l = i; l < c; l++) {
                    for (j = 0; j < r; j++) 
                        run_sum[j] += matrix[j][l];
                    cur_max  = INT_MIN;
                    cur_sum = 0;
                    dict.clear();
                    dict.insert(0);
                    for (int sum : run_sum) {
                        cur_sum += sum;
                        auto it = dict.lower_bound(cur_sum-k);
                        if (it != dict.end()) 
                            cur_max = max(cur_max,cur_sum-*it);
                        dict.insert(cur_sum);
                    }
                    ans = max(cur_max,ans);
                }
            }
        }
        return ans;
    }
};
