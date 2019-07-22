class Solution {
public:
    vector<int> diStringMatch(string S) {
        int i, n = S.length();
        int big = n, small = 0;
        vector<int> ans(n+1,0);
        for (i = 0; i < n; i++) {
            if (S[i] == 'D') {
                ans[i] = big;
                big--;
            }
            else {
                ans[i] = small;
                small++;
            }
        }
        ans[i] = small;
        return ans;
    }
};
