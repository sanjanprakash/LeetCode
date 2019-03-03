class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        int r,c;
        for (r = 0; r <= rowIndex; r++) {
            ans.push_back(1);
            for (c = r-1; c > 0; c--)
                ans[c] += ans[c-1];
        }
        return ans;
    }
};
