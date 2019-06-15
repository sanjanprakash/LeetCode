class Solution {
public:
    int computeArea(long long int A, long long int B, long long int C, long long int D, long long int E, long long int F, long long int G, long long int H) {
        long long int ar_a = (C-A)*(D-B), ar_b = (G-E)*(H-F);
        long long int r = min(C,G);
        long long int l = max(A,E);
        long long int u = min(H,D);
        long long int d = max(B,F);        
        long long int inter = (r-l > 0 && u-d > 0) ? (r-l)*(u-d) : 0;
        return ar_a + ar_b - inter;
    }
};
