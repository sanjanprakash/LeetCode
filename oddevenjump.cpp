class Solution {
public:    
    int oddEvenJumps(vector<int>& A) {
        int ans = 1;
        int n = A.size(), i;
        map<int,int> seen;
        map<int,int>::iterator it;
        bool *even_check = new bool[n], *odd_check = new bool[n];
        seen[A[n-1]] = n-1;       
        for (i = 0; i < n-1; i++) {
            even_check[i] = false;
            odd_check[i] = false;
        }
        even_check[n-1] = true;
        odd_check[n-1] = true;
        for (i = n-2; i >= 0; i--) {
            it = seen.lower_bound(A[i]);
            if (it != seen.end())
                odd_check[i] = even_check[it->second];
            if (odd_check[i])
                ans++;
            it = seen.upper_bound(A[i]);
            if (it != seen.begin()) {
                it--;
                even_check[i] = odd_check[it->second];
            }
            seen[A[i]] = i;
        }
        return ans;
    }
};
