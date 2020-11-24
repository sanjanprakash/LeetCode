class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        int l = 0, r = 0;
        char op;
        istringstream ss('+' + s + '+');
        while (ss >> op) {
            if (op == '+' || op == '-') {
                ans += l;
                ss >> l;
                l *= (op == '-') ? -1 : 1;
            }
            else {
                ss >> r;
                l = (op == '*') ? l*r : l/r;
            }
        }
        return ans;
    }
};
