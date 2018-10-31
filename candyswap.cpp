class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        int i,j, sum = 0;
        for (i = 0; i < A.size(); i++)
            sum += A[i];
        for (i = 0; i < B.size(); i++)
            sum -= B[i];
        i = 0;
        j = 0;
        vector<int>ans;
        while (i < A.size() && j < B.size()) {
            if ((A[i] - B[j])*2 == sum) {
                ans.push_back(A[i]);
                ans.push_back(B[j]);
                return ans;
            }
            if ((A[i] - B[j])*2 < sum)
                i++;
            else
                j++;
        }
    }
};
