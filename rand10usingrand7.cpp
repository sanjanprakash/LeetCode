// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        int r, c, idx;
        while (true) {
            r = rand7();
            c = rand7();
            idx = r + (c-1)*7;
            if (idx <= 40)
                break;
        }
        return 1 + (idx%10);
    }
};
