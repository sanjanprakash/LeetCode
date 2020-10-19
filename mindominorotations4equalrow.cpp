class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int i, n = A.size();
        int theOne;
        bool notPossible = true;
        vector<int> freqsA(7, 0), freqsB(7, 0), all(7, 0);
        for (i = 0; i < n; i++) {
            freqsA[A[i]]++;
            all[A[i]]++;
            freqsB[B[i]]++;
            all[B[i]]++;
            all[A[i]] -= (A[i] == B[i]);
        }
        for (i = 1; i < 7; i++) {
            if (all[i] >= n) {
                notPossible = false;
                theOne = i;
            }
        }
        return notPossible ? -1 : min(n-freqsA[theOne], n-freqsB[theOne]);
    }
};
