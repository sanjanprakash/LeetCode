class Solution {
public:
    void dfs(int temp, int digits, int K, vector<int>& result) {
        int i, last = temp%10;
        if (!digits) 
            result.push_back(temp);
        else {
            for (i = 0; i < 10; i++) {
                if (abs(last-i) == K)
                    dfs(temp*10+i, digits-1, K, result);
            }
        }
    }
    
    vector<int> numsSameConsecDiff(int N, int K) {
        int i;
        vector<int> ans;
        if (N == 1)
            ans.push_back(0);
        for (i = 1; i < 10; i++) 
            dfs(i, N-1, K, ans);
        return ans;
    }
};
