class Solution {
public:
    int hIndex(vector<int>& citations) {
        int i, n = citations.size(), ans = -1;
        if (n < 2)
            return n == 1 && !citations[0] ? n-1 : n;
        sort(citations.begin(),citations.end());
        for (i = 0; i < n; i++) {
            if (n-i <= citations[i])
                ans = max(ans,n-i);
            else
                ans = citations[i];
        }
        return ans;
    }
};
