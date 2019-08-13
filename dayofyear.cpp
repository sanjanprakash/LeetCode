class Solution {
public:
    int dayOfYear(string date) {
        int i;
        int ans;
        int days[12] = {0,31,59,90,120,151,181,212,243,273,304,334};
        int d = 0, m = 0, y = 0;
        for (i = 0; i < 4; i++)
            y = 10*y + date[i]-'0';
        for (i = 5; i < 7; i++)
            m = 10*m + date[i]-'0';
        for (i = 8; i < 10; i++)
            d = d*10 + date[i]-'0';
        ans = days[m-1] + d;
        if (y%4 == 0) {
            if ((y%400 == 0 || y%100) && m > 2)
                ans++;
        }
        return ans;
    }
};
