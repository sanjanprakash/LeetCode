class Solution {
public:
    string toLowerCase(string str) {
        int i;
        for (i = 0; i < str.length(); i++) {
            if (str[i] > 64 && str[i] < 91)
                str[i] = str[i] + 32;
        }
        return str;
    }
};
