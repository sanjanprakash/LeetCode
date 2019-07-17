/**
 * // This is the Master's API interface.
 * // You should not implement it, or speculate about its implementation
 * class Master {
 *   public:
 *     int guess(string word);
 * };
 */
class Solution {
public:
    void findSecretWord(vector<string>& wordlist, Master& master) {
        int i, j;
        int curr_score, curr_max, minim, min_id;
        int matches;
        vector<int> choices, next_choices;
        unordered_map<int,int> score_freqs;
        for (i = 0; i < wordlist.size(); i++)
            choices.push_back(i);
        while (choices.size()) {
            minim = INT_MAX;
            min_id = -1;
            for (i = 0; i < wordlist.size(); i++) {
                score_freqs.clear();
                curr_max = 0;
                for (auto &y : choices) {
                    if (wordlist[i] != wordlist[y]) {
                        curr_score = scorer(wordlist[i],wordlist[y]);
                        score_freqs[curr_score]++;
                        curr_max = max(curr_max,score_freqs[curr_score]);
                    }
                }
                if (minim > curr_max) {
                    minim = min(minim,curr_max);
                    min_id = i;
                }
            }
            matches = master.guess(wordlist[min_id]);
            if (matches == 6)
                return;
            next_choices.clear();
            for (auto &x : choices) {
                if (scorer(wordlist[min_id],wordlist[x]) == matches)
                    next_choices.push_back(x);
            }
            choices = next_choices;
        }
    }
    
    int scorer(string &a, string &b) {
        int i;
        int score = 0;
        for (i = 0; i < 6; i++)
            score += a[i] == b[i] ? 1 : 0;
        return score;
    }
};
