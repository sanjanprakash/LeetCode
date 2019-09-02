class Solution {
public:
    int factorial(int n, long long int ans) {
        if (n <= 1)
            return ans;
        return factorial(n-1,(n*ans)%1000000007);
    }
    
    int numPrimeArrangements(int n) {
        int i,j;
        int num_primes = 0, ans;
        vector<int> sieve(n+1,-1);
        if (n > 1) {
            i = 2;
            while (i <= n) {
                if (sieve[i] == -1) {
                    sieve[i] = 1;
                    for (j = 2*i; j <= n; j += i)
                        sieve[j] = 0;
                }
                i++;
            }            
        }
        for (i = 2; i <= n; i++)
            num_primes += sieve[i];
        ans = factorial(num_primes,1);
        return factorial(n-num_primes,ans);
    }
};
