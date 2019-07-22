class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        int i = A.size()-1, j, dig;
        while (K) {
            j = i;
            dig = K%10;
            K /= 10;
            if (j > -1) {
                while (dig && j > -1) {
                    A[j] += dig;
                    dig = A[j]/10;
                    A[j] %= 10;
                    j--;
                }
                if (dig) {
                    A.insert(A.begin(),dig);
                    i++;
                }
                i--;
            }
            else
                A.insert(A.begin(),dig);
        }
        return A;
    }
};
