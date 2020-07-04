class Solution {
public:
    bool checkRecord(string s) {
        int lates = 0, absents = 0;
        bool isLate = false;
        for (char x : s) {
            if (x == 'L') {
                lates++;
                if (lates > 2)
                    isLate = true;
            }
            else {
                if (lates)
                    lates = 0;
                if (x == 'A')
                    absents++;
            }
        }
        return !isLate && absents < 2;
    }
};
