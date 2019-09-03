class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int i,j,n = s.length();
        int odd;
        bool temp;
        vector<vector<int> > freq(n+1,vector<int>(26,0));
        vector<int> uno(26,0);
        vector<bool> ans;
        for (i = 0; i < n; i++) {
            for (j = 0; j < 26; j++)
                freq[i+1][j] = freq[i][j];
            freq[i+1][s[i]-'a']++;
        }
        for (auto &x : queries) {
            odd = 0;
            for (i = 0; i < 26; i++) {
                uno[i] = freq[x[1]+1][i]-freq[x[0]][i];
                if (uno[i]%2)
                    odd++;
            }
            ans.push_back(odd/2 <= x[2]);
        }
        return ans;
    }
};
