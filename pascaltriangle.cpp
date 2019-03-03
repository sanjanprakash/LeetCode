class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > ans;
        int i,j;
        for (i = 0; i < numRows; i++) {
            vector<int> row;
            for (j = 0; j < i+1; j++) {
                if (i == j || j == 0)
                    row.push_back(1);
                else
                    row.push_back(ans[i-1][j-1] + ans[i-1][j]);
            }
            ans.push_back(row);
        }
        return ans;
    }
};
