class Solution {
public:
    vector<string> expand(string S) {
        int i, j, k, m, n = S.length();
        int num_words = 1, num_type;
        vector<vector<char> > dict;
        vector<char> uno;
        vector<string> ans;
        for (i = 0; i < n; i++) {
            if (S[i] > 96 && S[i] < 123) {
                uno.push_back(S[i]);
                if (i+1 >= n || S[i+1] != ',') {
                    dict.push_back(uno);
                    uno.clear();
                }
            }
        }
        for (i = 0; i < dict.size(); i++) {
            num_words *= dict[i].size();
            sort(dict[i].begin(),dict[i].end());
        }
        for (i = 0; i < num_words; i++)
            ans.push_back("");
               
        k = 0;
        num_type = num_words;
        while (k < dict.size()) {
            i = 0;
            m = dict[k].size();
            while (i < num_words) {
                j = 0;
                while (j < num_type) {
                    ans[i+j] += dict[k][j*m/num_type];
                    j++;
                }
                i += j;
            }
            num_type /= m;
            k++;
        }
        return ans;
    }
};
