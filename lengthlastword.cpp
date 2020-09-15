class Solution {
public:
    int lengthOfLastWord(string s) {
        string word = "";
        istringstream ss(s);
        while (ss >> word);
        return word.length();
    }
};
