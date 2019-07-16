class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int ans = 1;
        int tests = 1+minutesToTest/minutesToDie;
        int times = tests;
        if (buckets == 1)
            return 0;
        while (times < buckets) {
            times *= tests;
            ans++;
        }
        return ans;
    }
};
