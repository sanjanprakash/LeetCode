class Solution {
public:
    int binaryGap(int N) {
        int gap = 0, ans = 0;
        while (N) {
            if (N%2) {
                if (ans) {
                    ans = max(ans,gap); 
                    gap = 0;
                }
                else
                    ans = -1;
                gap++;
            }
            else {
                if (ans)
                    gap++;                           
            }
            N /= 2;
        }
        return ans > -1 ? ans : 0;
    }
};
