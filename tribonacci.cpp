class Solution {
public:
    int tail_trib(int a, int b, int c, int n) {
        if (n == 2)
            return c;
        if (n == 1)
            return b;
        if (n == 0)
            return a;
        return tail_trib(b,c,a+b+c,n-1);
    }
    
    int tribonacci(int n) {
        return tail_trib(0,1,1,n);
    }
};
