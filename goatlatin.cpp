class Solution {
public:
    string toGoatLatin(string S) {
        int i;
        char start = '_';
        bool begin = true;
        string word = "", ans = "";
        string tail = "a";
        for (i = 0; i < S.length(); i++) {
            if (S[i] == ' ') {
                if (start != '_')
                    word += start;
                word += "ma" + tail;
                tail += "a";
                start = '_';
                ans += word + " ";
                word = "";
                begin = true;
            }
            else if (begin && word.length() == 0) {
                if (S[i] != 65 && S[i] != 97 && S[i] != 69 && S[i] != 101 && S[i] != 73 && S[i] != 105 && S[i] != 79 && S[i] != 111 && S[i] != 85 && S[i] != 117)
                    start = S[i];
                else
                    word += S[i];
                begin = false;
            }
            else
                word += S[i];
        }
        if (start != '_') 
            word += start;
        word += "ma" + tail;
        ans += word;
        return ans;
    }
};
