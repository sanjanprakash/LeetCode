class Solution {
public:
    void oldOrder(string &ori, char *order) {
        int i;
        for (i = 0; i < ori.length(); i++) 
            ori[i] = order[int(ori[i]) - 97];
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        char *letters = new char[26];
        int i;
        for (i = 0; i < 26; i++) 
            letters[int(order[i]) - 97] = char(97 + i);
        for (i = 0; i < words.size(); i++) 
            oldOrder(words[i],letters);
        for (i = 0; i < words.size() - 1; i++) {
            if (words[i] > words[i+1])
                return false;
        }
        return true;
    }
};
