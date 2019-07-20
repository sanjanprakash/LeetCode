class Solution {
private:
    long long int mod = 1000000007;
public:
    long long int factorial(long long int n, long long int prod) {
        if (n <= 1)
            return prod;
        return factorial(n-1,(n*prod)%mod);
    }
    
    long long int helper(int N, int L, int K, vector<vector<long long int> > &dp) {
        long long int all_played, last_not_played;
        if (K > N || N > L || K < 0)
            return 0;
        if (K == N && N == L) {
            dp[L][N] = factorial(N,1);
            return dp[L][N];
        }
        if (dp[L][N] != -1)
            return dp[L][N];
        all_played = helper(N,L-1,K,dp);
        last_not_played = helper(N-1,L-1,K,dp);
        dp[L][N] = (((N-K)*all_played)%mod + (N*last_not_played)%mod)%mod;
        return dp[L][N];
    }
    
    int numMusicPlaylists(int N, int L, int K) {
        vector<vector<long long int> > dp(101,vector<long long int>(101,-1));
        return helper(N,L,K,dp);
    }
};
