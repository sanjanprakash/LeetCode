class Solution {
public:
    int numJewelsInStones(string J, string S) {
        int i,j,count = 0;
        for (i = 0; i < J.length(); i++) {
            for (j = 0; j < S.length(); j++) {
                if (J[i] == S[j])
                    count++;
            }
        }
        return count;
    }
};
