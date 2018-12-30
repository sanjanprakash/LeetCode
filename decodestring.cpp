class Solution {
public:
    int strToInt(string n) {
        int i, ans = 0;
        for (i = 0; i < n.length(); i++) {
            ans *= 10;
            ans += n[i] - '0';
        }
        return ans;
    }
    
    string decodeString(string s) {
        stack<char> S;
        stack<int> nums;
        int i,j,k,repeats;
        string p = "", ans = "", num = "";
        for (i = 0; i < s.length(); i++) {
            if (int(s[i]) > 47 && int(s[i]) < 58) 
                num = num + s[i];
            else {
                if (num.length() > 0) {
                    repeats = strToInt(num);
                    nums.push(repeats);
                    num = "";
                }
                if (s[i] != ']')
                    S.push(s[i]);
                else {
                    while (S.top() != '[') {
                        p = S.top() + p;
                        S.pop();
                    }
                    S.pop();
                    repeats = nums.top();
                    nums.pop();
                    for (j = 0; j < repeats; j++) {
                        for (k = 0; k < p.length(); k++)
                            S.push(p[k]);
                    }
                    p = "";
                }
            }
        }
        while(!S.empty()) {
            ans = S.top() + ans;
            S.pop();
        }
        return ans;
    }
};
