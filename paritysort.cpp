class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        vector<int>ans;
        int i;
        for(i = 0; i < A.size(); i++) {
            if (A[i] % 2 == 0)
                ans.push_back(A[i]);
        }
        for(i = 0; i < A.size(); i++) {
            if (A[i] % 2 == 1)
                ans.push_back(A[i]);
        }
        return ans;
    }
};
