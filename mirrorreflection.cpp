class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0)
            return a;
        return gcd(b,a%b);
    }
    
    int mirrorReflection(int p, int q) {
        int vert_dist, lr_bounce, ud_bounce;
        vert_dist = p*q/gcd(p,q);
        lr_bounce = vert_dist/q;
        ud_bounce = vert_dist/p;
        if (lr_bounce%2 == 0 && ud_bounce%2)
            return 2;
        if (lr_bounce%2 && ud_bounce%2 == 0)
            return 0;
        return 1;
    }
};
