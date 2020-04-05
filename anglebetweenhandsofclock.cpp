class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hh = ((hour + 12) % 12) * 30.0;
        double hm = (minutes * 30.0)/60.0;
        double mm = minutes * 6.0;
        double ans = mm-hh-hm;
        if (ans < 0.0)
            ans *= -1.0;
        if (ans > 180.0)
            return 360.0-ans;
        return ans;
    }
};
