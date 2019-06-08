class Solution {
public:
    bool detectCapitalUse(string word) {
        int i;
        int caps = 0, small = 0;
        if (word[i] > 64 && word[i] < 91) {
            for (i = 1; i < word.length(); i++) {
                if (word[i] > 64 && word[i] < 91)
                    caps++;
                else
                    small++;
                if (caps > 0 && small > 0)
                    return false;
            }
        }
        else {
            for (i = 0; i < word.length(); i++) {
                if (word[i] > 90)
                    small++;
                else
                    caps++;
                if (caps)
                    return false;
            }
        }
        return true;
    }
};
