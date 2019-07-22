class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.length()-1, j = b.length()-1;
        int dig, carry = 0;
        string ans = "";
        while (i > -1 & j > -1) {
            dig = (a[i]-'0' + b[j]-'0' + carry)%2;
            carry = (a[i]-'0' + b[j]-'0' + carry)/2;
            ans = to_string(dig) + ans;
            i--;
            j--;
        }
        while (i > -1) {
            dig = (a[i]-'0' + carry)%2;
            carry = (a[i]-'0' + carry)/2;
            ans = to_string(dig) + ans;
            i--;
        }
        while (j > -1) {
            dig = (b[j]-'0' + carry)%2;
            carry = (b[j]-'0' + carry)/2;
            ans = to_string(dig) + ans;
            j--;
        }
        if (carry)
            ans = to_string(carry) + ans;
        return ans;
    }
};
