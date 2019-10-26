class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int l = 0, r = 0, n = A.size();
        int ans = 0;
        vector<int> freqs(2,0);
        while (r < n) {
            freqs[A[r++]]++;
            while (l < r && freqs[0] > K) 
                freqs[A[l++]]--;
            ans = max(ans,r-l);
        }
        return ans;
    }
};
