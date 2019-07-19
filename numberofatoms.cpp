class Solution {
private:
    map<string,int> freqs;
public:
    void counter(string formula, int num) {
        int i, j, k;
        int n = formula.length(), open;
        int group_rep = 0, rep = 0;
        string piece, atom = "";
        for (i = 0; i < n; i++) {
            if (formula[i] == '(') {
                j = i+1;
                piece = "";
                open = 0;
                while (formula[j] != ')' || open) {
                    if (formula[j] == '(')
                        open++;
                    else if (formula[j] == ')')
                        open--;
                    piece += formula[j];
                    j++;
                }
                k = j+1;
                if (k < n && formula[k] >= '0' && formula[k] <= '9') {
                    group_rep = 0;
                    while (k < n && formula[k] >= '0' && formula[k] <= '9') {
                        group_rep *= 10;
                        group_rep += formula[k] - '0';
                        k++;
                    }
                }
                else
                    group_rep = 1;
                counter(piece,group_rep*num);
                group_rep = 0;
                i = k == j+1 ? j : k-1;
                if (formula[i] == '(')
                    i--;
            }
            else {
                if (formula[i] >= '0' && formula[i] <= '9') {
                    rep *= 10;
                    rep += formula[i] - '0';
                }
                else {
                    if (atom != "" && formula[i] >= 'A' && formula[i] <= 'Z') {
                        freqs[atom] += rep ? rep*num : num;
                        rep = 0;
                        atom = formula[i];
                    }
                    else
                        atom += formula[i];
                }
            }
        }
        if (atom != "") 
            freqs[atom] += rep ? rep*num : num;
    }
    
    string countOfAtoms(string formula) {
        string ans = "";
        counter(formula,1);
        for (auto &x : freqs) {
            ans += x.first;
            if (x.second != 1)
                ans += to_string(x.second);
        }
        return ans;
    }
};
