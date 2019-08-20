class Solution {
public:
    int hIndex(vector<int>& citations) {
        int i, n = citations.size(), ans = -1;
        if (n < 2)
            return n == 1 && !citations[0] ? n-1 : n;
        sort(citations.begin(),citations.end());
        for (i = 0; i < n; i++) 
            ans = n-i <= citations[i] ? max(ans,n-i) : citations[i];
        return ans;
    }
};
