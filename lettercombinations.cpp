class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        vector<char> X;
        vector<vector <char> > dict;
        dict.push_back(X);
        dict.push_back(X);
        int i,j,k,letters = 97,num,num_prev;
        for (i = 0; i < 8; i++) {
            vector<char> X;
            j = 3;
            if (i == 5 || i == 7)
                j = 4;
            for (k = 0; k < j; k++)
                X.push_back(char(letters+k));
            letters += k;
            dict.push_back(X);
        }
        for (i = 0; i < digits.length(); i++) {
            string temp;
            num = int(digits[i]) - 48;
            if (i == 0) {
                for (j = 0; j < dict[num].size(); j++) {
                    temp = dict[num][j];
                    ans.push_back(temp);
                }
            }
            else {
                num_prev = ans.size();
                for (j = 1; j < dict[num].size(); j++) {
                    for (k = 0; k < num_prev; k++)
                        ans.push_back(ans[k] + dict[num][j]);
                }
                for (j = 0; j < num_prev; j++)
                    ans[j] = ans[j] + dict[num][0];
            }
        }
        return ans;
    }
};
