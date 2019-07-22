class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.length()-1, j = num2.length()-1;
        int dig, carry = 0;
        string ans = "";
        while (i > -1 && j > -1) {
            dig = (num1[i]-'0' + num2[j]-'0' + carry)%10;
            carry = (num1[i]-'0' + num2[j]-'0' + carry)/10;
            ans = to_string(dig) + ans;
            i--;
            j--;
        }
        while (i > -1) {
            dig = (num1[i]-'0' + carry)%10;
            carry = (num1[i]-'0' + carry)/10;
            ans = to_string(dig) + ans;
            i--;
        }
        while (j > -1) {
            dig = (num2[j]-'0' + carry)%10;
            carry = (num2[j]-'0' + carry)/10;
            ans = to_string(dig) + ans;
            j--;
        }
        if (carry)
            ans = to_string(carry) + ans;
        return ans;
    }
};
