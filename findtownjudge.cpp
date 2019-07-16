class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        int i;
        vector<int> degree(N+1,0);
        for (auto &x : trust) {
            degree[x[1]]++;
            degree[x[0]]--;
        }
        for (i = 1; i <= N; i++) {
            if (degree[i] == N-1)
                return i;
        }
        return -1;
    }
};
