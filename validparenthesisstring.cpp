class Solution {
public:
    bool checkValidString(string s) {
        int l = 0, r = 0;
        for (char &c : s) {
            if (c == '(') 
                l++;
            else
                l--;
            if (c != ')')
                r++;
            else
                r--;
            if (r < 0)
                break;
            l = max(0, l); 
        }
        return l == 0;
    }
};
