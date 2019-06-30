class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        int i = 0, j = 0;
        int m = A.size(), n = B.size();
        int l, r;
        vector<vector<int> > ans;
        while (i < m && j < n) {
            l = max(A[i][0],B[j][0]);
            r = min(A[i][1],B[j][1]);
            if (l <= r) 
                ans.push_back({l,r});
            A[i][1] < B[j][1] ? i++ : j++;
        }
        return ans;
    }
};
