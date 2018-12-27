class Solution {
public:
    vector<int> prisonAfterNDays(vector<int>& cells, int N) {
        vector<vector<int> > X;
        int i,j;
        X.push_back(cells);
        for (i = 1; i <= 14; i++) {
            vector<int>temp;
            temp.push_back(0);
            for (j = 1; j < 7; j++) {
                if (X[i-1][j-1] == X[i-1][j+1])
                    temp.push_back(1);
                else
                    temp.push_back(0);
            }
            temp.push_back(0);
            X.push_back(temp);
        }
        if (X[0][7] == 0 && X[0][0] == 0)
            return X[N%14]; 
        X.erase(X.begin());
        return X[(N-1)%14];
    }
};
