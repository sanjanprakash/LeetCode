// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n, m;
        int ans;
        while (l <= r) {
            m = l + (r-l)/2;
            if (!isBadVersion(m))
                l = m+1;
            else {
                ans = m;
                r = m-1;
            }
        }
        return ans;
    }
};
