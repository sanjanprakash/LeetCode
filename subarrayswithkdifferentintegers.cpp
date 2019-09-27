class Solution {
public:
    int atMostK(vector<int>& A, int k) {
        int unique = 0, n = A.size();
        int ans = 0;
        int start = 0, end = 0;
        unordered_map<int,int> freqs;
        while (start < n && end < n) {
            if (!freqs[A[end]])
                unique++;
            freqs[A[end]]++;
            while (unique > k) {
                freqs[A[start]]--;
                if (!freqs[A[start]])
                    unique--;
                start++;
            }
            end++;
            ans += end-start+1;
        }
        return ans;
    }    
    
    int subarraysWithKDistinct(vector<int>& A, int K) {
        return atMostK(A,K) - atMostK(A,K-1);
    }
};
