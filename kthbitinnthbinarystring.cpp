class Solution {
public:
    char findKthBit(int n, int k) {
        int i, j;
        string old, neo = "0";
        for (i = 2; i <= n; i++) {
            old = neo;
            neo += "1";
            for (j = old.length()-1; j > -1; j--) 
                neo += old[j] == '0' ? "1" : "0";
        }
        return neo[k-1];
    }
};
