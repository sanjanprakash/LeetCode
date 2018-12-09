class Solution {
public:
    bool canReorderDoubled(vector<int>& A) {
        vector<int> B, C;
        int i;
        for (i = 0; i < A.size(); i++) {
            if (A[i] < 0)
                B.push_back(A[i]);
            else
                C.push_back(A[i]);
        }
        sort(B.begin(),B.end(),greater<int>());
        sort(C.begin(),C.end());
        vector<int>::iterator it;
        int temp;
        while (B.size() != 0) {
            temp = B[0];
            it = find(B.begin()+1, B.end(), 2*temp);
            if (it == B.begin() || it == B.end())
                return false;
            B.erase(it);
            B.erase(B.begin());
        }
        while (C.size() != 0) {
            temp = C[0];
            it = find(C.begin()+1, C.end(), 2*temp);
            if (it == C.begin() || it == C.end())
                return false;
            C.erase(it);
            C.erase(C.begin());
        }
        return true;
    }
};
