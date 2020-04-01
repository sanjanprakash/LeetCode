class Solution {
public:
    int numTeams(vector<int>& rating) {
        int i, j;
        int n = rating.size();
        int ans = 0;
        for (i = 1; i < n-1; i++) {
            vector<int> less(2,0), great(2,0);
            for (j = 0; j < n; j++) {
                if (i != j) {
                    if (rating[i] < rating[j])
                        great[i<j]++;
                    else
                        less[i<j]++;
                }
            }
            ans += (great[0]*less[1]) + (great[1]*less[0]);
        }
        return ans;
    }
};
