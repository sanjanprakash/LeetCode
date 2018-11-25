class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(),tokens.end());
        int pts = 0,ans = 0;
        int i = 0,j = tokens.size() - 1;
        while (i <= j && pts >= 0) {
            if (tokens[i] <= P) {
                P -= tokens[i];
                pts++;
                ans = max(ans,pts);
                i++;
            }
            else {
                P += tokens[j];
                pts--;
                j--;
            }
        }
        return ans;
    }
};
