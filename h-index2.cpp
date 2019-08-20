class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, h = n, m;
        int ans = -1;
        if (n < 2)
            return n == 1 && !citations[0] ? n-1 : n;
        while (l < h) {
            m = l + (h-l)/2;
            if (n-m <= citations[m]) {
                ans = max(ans,n-m);
                h = m;
            }
            else {
                ans = max(ans,citations[m]);
                l = m+1;
            }
        }
        return ans;
    }
};
