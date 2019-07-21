class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int i;
        int signs[2] = {-1,1};
        int big, small, ans = INT_MIN;
        for (auto &x : signs) {
            for (auto &y : signs) {
                big = INT_MIN;
                small = INT_MAX;
                for (i = 0; i < arr1.size(); i++) {
                    big = max(big,x*arr1[i]+y*arr2[i]+i);
                    small = min(small,x*arr1[i]+y*arr2[i]+i);        
                }
                ans = max(ans,big-small);
            }
        }
        return ans;
    }
};
