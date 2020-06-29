class Solution {
public:
    bool plenty(int x, int m, int n, int k) {
        int i, ans = 0;
        for (i = 1; i <= m; i++)
            ans += min(x/i, n);
        return ans >= k;
    }
    
    int findKthNumber(int m, int n, int k) {
        int l = 0, h = m*n, mid;
        while (l < h) {
            mid = l + (h-l)/2;
            if (plenty(mid, m, n, k))
                h = mid;
            else
                l = mid+1;
        }
        return l;
    }
};
