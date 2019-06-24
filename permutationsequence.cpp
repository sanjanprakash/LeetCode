class Solution {
public:
    void helper(int k, vector<int> &digits, string &ans) {
        int factorial[10] = {1,1,2,6,24,120,720,5040,40320,362880};
        if (digits.size()) {
            int n = digits.size();
            int digit_id = k%factorial[n-1] ? k/factorial[n-1] : (k-1)/factorial[n-1];
            k = k%factorial[n-1] ? k%factorial[n-1] : factorial[n-1];
            ans += to_string(digits[digit_id]);
            digits.erase(digits.begin()+digit_id);
            helper(k,digits,ans);
        }
    }
    
    string getPermutation(int n, int k) {
        int i = 1;
        string ans = "";
        vector<int> digits;
        while (i <= n) {
            digits.push_back(i);
            i++;
        }
        helper(k,digits,ans);
        return ans;
    }
};
