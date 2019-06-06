class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        int i,j;
        string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        string trans;
        map<string,int> freqs;
        for (i = 0; i < words.size(); i++) {
            trans = "";
            for (j = 0; j < words[i].length(); j++)
                trans += morse[words[i][j]-97];
            freqs[trans]++;
        }
        return freqs.size();
    }
};
