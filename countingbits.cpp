class Solution {
public:
    vector<int> countBits(int num) {
        int i, k = 2;
        vector<int> ans(num+1,0);
        if (num > 0) {
            ans[1] = 1;
            for (i = 2; i <= num; i++) {
                if (!(i & (i-1))) 
                    k = i;
                ans[i] = ans[i-k] + 1;
            }
        }
        return ans;
    }
};
