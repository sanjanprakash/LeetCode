class Solution {
public:
    vector<string> letterCombinations(string digits) {
        int numLetters[10] = {0,0,3,3,3,3,3,4,3,4};
        char letters[10] = {'_','_','a','d','g','j','m','p','t','w'};
        int i,j,k;
        int num;
        int prev = 0;
        vector<string> ans;
        string temp;
        for (k = 0; k < digits.length(); k++) {
            num = digits[k] - '0';
            if (k == 0) {
                for (i = 0; i < numLetters[num]; i++) {
                    temp = char(letters[num]+i);
                    ans.push_back(temp);
                }
            }
            else {
                for (j = 0; j < numLetters[num]-1; j++) {
                    for (i = 0; i < prev; i++)
                        ans.push_back(ans[i]);
                }
                for (j = 0; j < numLetters[num]; j++) {
                    for (i = j*prev; i < (j+1)*prev; i++)
                        ans[i] += char(letters[num]+j);
                }
            }
            prev = ans.size();
        }
        return ans;
    }
};
