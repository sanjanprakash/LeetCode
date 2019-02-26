class Solution {
public:
    bool canCross(vector<int>& stones) {
        int i;
        int ans = 0;
        vector<vector<bool> > check;
        for (i = 0; i < stones.size(); i++) {
            vector<bool> row(stones.size(),false);
            check.push_back(row);
        }
        Crosser(stones,0,1,ans,check);
        return stones[1] == 1 && ans == stones.size() - 1;
    }
    
    void Crosser(vector<int>& stones, int curr, int jump, int &ans, vector<vector<bool> > &check) {
        if (check[curr][jump])
            return;
        int i,d;
        int n = stones.size();
        check[curr][jump] = true;
        if (ans < n-1 && curr < n-1) {
            for (i = curr+1; i < n; i++) {
                d = stones[i] - stones[curr];
                if (jump == d || jump-1 == d || jump+1 == d) {
                    ans = max(ans,i);
                    Crosser(stones,i,d,ans,check);
                }
            }
        }
    }
};
