class Solution {
public:
    string shiftingLetters(string S, vector<int>& shifts) {
        int n = shifts.size(), i;
        shifts[n-1] = shifts[n-1] % 26;
        for (i = n-2; i >= 0; i--)
            shifts[i] = (shifts[i] + shifts[i+1]) % 26;
        for (i = 0; i < n; i++) {
            if (int(S[i]) + shifts[i] > 122)
                S[i] = char(int(S[i]) + shifts[i] - 26);
            else
                S[i] = char(int(S[i]) + shifts[i]);
        }
        return S;
    }
};
