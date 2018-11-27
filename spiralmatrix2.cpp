class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector< vector<int>> ans(n, vector<int> (n));
        int count = 0,i,j;
        int top_lr_start = 0, top_lr_end = n-1;
        int right_ud_start = 0, right_ud_end = n-1;
        int bottom_rl_start = n-1, bottom_rl_end = 0;
        int left_du_start = n-1, left_du_end = 0;
        if (n == 1) {
            ans[0][0] = 1;
            return ans;
        }
        while (count <= n*n) {
            for (i = top_lr_start; i <= top_lr_end; i++) {
                count++;
                ans[right_ud_start][i] = count;
            }
            if (count == n*n) 
                break;
            right_ud_start++;
            left_du_end++;
            for (i = right_ud_start; i <= right_ud_end; i++) {
                count++;
                ans[i][top_lr_end] = count;
            }
            if (count == n*n) 
                break;
            top_lr_end--;
            bottom_rl_start--;
            for (i = bottom_rl_start; i >= bottom_rl_end; i--) {
                count++;
                ans[left_du_start][i] = count;
            }
            if (count == n*n) 
                break;
            left_du_start--;
            right_ud_end--;
            for (i = left_du_start; i >= left_du_end; i--) {
                count++;
                ans[i][top_lr_start] = count;
            }
            if (count == n*n) 
                break;
            top_lr_start++;
            bottom_rl_end++;
        }
        return ans;
    }
};
