class Solution {
public:
    string reverseOnlyLetters(string S) {
        int l = 0, r = S.length()-1;
        char temp;
        while (l < r) {
            while (l < S.length() && (S[l] < 65 || S[l] > 90) && (S[l] < 97 || S[l] > 122)) 
                l++;
            while (r > -1 && (S[r] < 65 || S[r] > 90) && (S[r] < 97 || S[r] > 122)) 
                r--;
            if (l >= r)
                break;
            temp = S[l];
            S[l] = S[r];
            S[r] = temp;
            l++;
            r--;
        }
        return S;
    }
};
