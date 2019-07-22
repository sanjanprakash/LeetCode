class Solution {
public:
    vector<string> letterCasePermutation(string S) {
        int i = 0, j, n, change;
        string temp;
        vector<string> ans;
        ans.push_back(S);
        while (i < S.length()) {
            if (S[i] >= '0' && S[i] <= '9') {
                i++;
                continue;
            }
            if (S[i] >= 'a' && S[i] <= 'z')
                change = -32;
            else
                change = 32;
            n = ans.size();
            for (j = 0; j < n; j++) {
                temp = ans[j];
                temp[i] += change;
                ans.push_back(temp);
            }
            i++;
        }
        return ans;
    }
};
