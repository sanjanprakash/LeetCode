class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& A) {
        int i, odd_ind = 1, even_ind = 0;
        while (odd_ind < A.size() && even_ind < A.size()-1) {
            if (A[odd_ind]%2 == 1 && A[even_ind]%2 == 0) {
                odd_ind += 2;
                even_ind += 2;
            }
            else if (A[odd_ind]%2 == 0 && A[even_ind]%2 == 1) {
                A[odd_ind] ^= A[even_ind];
                A[even_ind] ^= A[odd_ind];
                A[odd_ind] ^= A[even_ind];
                odd_ind += 2;
                even_ind += 2;
            }
            else if (A[odd_ind]%2 == 1)
                odd_ind += 2;
            else
                even_ind += 2;
        }
        return A;
    }
};
