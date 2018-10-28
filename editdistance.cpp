class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.length(), n2 = word2.length();
        int i,j;
        int arr[n1 + 1][n2 + 1];
        for (i = 0; i <= n1; i++)
            arr[i][0] = i;
        for (i = 0; i <= n2; i++)
            arr[0][i] = i;
        for (i = 1; i <= n1; i++) {
            for (j = 1; j <= n2; j++) {
                if (word1[i-1] == word2[j-1])
                    arr[i][j] = arr[i-1][j-1];
                else {
                    arr[i][j] = min(arr[i-1][j],arr[i][j-1]);
                    arr[i][j] = min(arr[i][j],arr[i-1][j-1]);
                    arr[i][j]++;
                }
            }
        }
        return arr[n1][n2];
    }
};
