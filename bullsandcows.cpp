class Solution {
public:
    string getHint(string secret, string guess) {
        int i, n = guess.length();
        int cows = 0, bulls = 0;
        vector<int> secret_freqs(10, 0), guess_freqs(10, 0);
        for (i = 0; i < n; i++) {
            if (secret[i] == guess[i])
                bulls++;
            else {
                secret_freqs[secret[i]-'0']++;
                guess_freqs[guess[i]-'0']++;
            }
        }
        for (i = 0; i < 10; i++) 
            cows += min(secret_freqs[i], guess_freqs[i]);
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
