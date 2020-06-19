class Solution {
public:
    long long int pow(int base, int exp, long long int mod) {
        long long int ans = 1;
        while (exp--) 
            ans = (ans*base)%mod;
        return ans;
    }
    
    long long int pow(int base, int exp) {
        long long int ans = 1;
        while (exp--)
            ans *= base;
        return ans;
    }
    
    int rabinKarp(int len, int base, long long int mod, vector<int> &numChars) {
        int i, n = numChars.size();
        long long hash = 0;
        long long int toRemove = pow(base, len, mod);
        unordered_set<long long int> hashes;
        for (i = 0; i < len; i++)
            hash = (hash*base + numChars[i])%mod;
        hashes.insert(hash);
        for (i = 1; i < n-len+1; i++) {
            hash = (hash*base - numChars[i-1]*toRemove % mod + mod)%mod;
            hash = (hash + numChars[i+len-1])%mod;
            if (hashes.find(hash) != hashes.end())
                return i;
            hashes.insert(hash);
        }
        return -1;
    }
    
    string longestDupSubstring(string S) {
        int i, n = S.length();
        int l = 1, r = n, len, begin;
        int base = 26;
        long long int mod = pow(2, 32);
        vector<int> numChars(n, 0);
        for (i = 0; i < n; i++)
            numChars[i] = S[i]-'a';
        while (l <= r) {
            len = l + (r-l)/2;
            if (rabinKarp(len, base, mod, numChars) != -1)
                l = len+1;
            else
                r = len-1;
        }
        begin = rabinKarp(l-1, base, mod, numChars);
        return S.substr(begin, l-1);
    }
};
