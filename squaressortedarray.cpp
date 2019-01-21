class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int i,j;
        vector<int>pos,neg;
        vector<int> ans;
        for (i = 0; i < A.size(); i++) {
            if (A[i] < 0)
                neg.insert(neg.begin(),A[i]*A[i]);
            else
                pos.push_back(A[i]*A[i]);
        }
        i = 0;
        j = 0;
        while (i < pos.size() && j < neg.size()) {
            if (pos[i] < neg[j]) {
                ans.push_back(pos[i]);
                i++;
            }
            else {
                ans.push_back(neg[j]);
                j++;
            }
        }
        while (i < pos.size()) {
            ans.push_back(pos[i]);
            i++;
        }
        while (j < neg.size()) {
            ans.push_back(neg[j]);
            j++;
        }
        return ans;
    }
};
