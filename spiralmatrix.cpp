class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m = matrix.size();
        if (m == 0)
            return ans;
        int n = matrix[0].size();
        if (n == 0)
            return ans;
        int i,j,count = 0;
        int top_lr_start = 0, top_lr_end = n-1;
        int right_ud_start = 0, right_ud_end = m-1;
        int bottom_rl_start = n-1, bottom_rl_end = 0;
        int left_du_start = m-1, left_du_end = 0;
        while (count <= m*n) {
            for (i = top_lr_start; i <= top_lr_end; i++) {
                count++;
                ans.push_back(matrix[right_ud_start][i]);
            }
            if (count == m*n) 
                break;
            right_ud_start++;
            left_du_end++;
            for (i = right_ud_start; i <= right_ud_end; i++) {
                count++;
                ans.push_back(matrix[i][top_lr_end]);
            }
            if (count == m*n) 
                break;
            top_lr_end--;
            bottom_rl_start--;
            for (i = bottom_rl_start; i >= bottom_rl_end; i--) {
                count++;
                ans.push_back(matrix[left_du_start][i]);
            }
            if (count == m*n) 
                break;
            left_du_start--;
            right_ud_end--;
            for (i = left_du_start; i >= left_du_end; i--) {
                count++;
                ans.push_back(matrix[i][top_lr_start]);
            }
            if (count == m*n) 
                break;
            top_lr_start++;
            bottom_rl_end++;
        }
        return ans;
    }
};
