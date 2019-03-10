// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int ans = 0, i;
        for (i = 1; i < n; i++) {
            if (knows(ans,i) == true)
                ans = i;
        }
        for (i = 0; i < n; i++) {
            if (i != ans && knows(ans,i) == true)
                return -1;
        }
        for (i = 0; i < n; i++) {
            if (i != ans && knows(i,ans) == false)
                return -1;
        }        
        return ans;
    }
};
