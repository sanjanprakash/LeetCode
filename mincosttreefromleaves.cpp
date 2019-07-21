class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        int i, ans = 0;
        int temp;
        deque<int> S;
        S.push_back(INT_MAX);
        for (auto &x : arr) {
            while (S.back() < x) {
                temp = S.back();
                S.pop_back();
                ans += temp*min(x,S.back());
            }
            S.push_back(x);
        }
        for (i = 1; i < S.size()-1; i++)
            ans += S[i]*S[i+1];
        return ans;
    }
};
