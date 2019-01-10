class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        int i = 1, check = 1;
        ans.push_back(0);
        while (i <= num) {
            if (i == check) {
                check *= 2;
                ans.push_back(1);
            }
            else
                ans.push_back(ans[i-check/2] + 1);
            i++;
        }
        return ans;
    }
};
