class Solution {
public:
    string multiply(string num1, string num2) {
        char digits[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
        vector<char>ans;
        string result = "";
        int n1 = num1.length();
        int n2 = num2.length();
        int temp,carry,neo;
        int i,j,multiplier;
        for (i = 0; i < n1 + n2; i++)
            ans.push_back('0');
        for (i = n2 - 1; i >= 0; i--) {
            multiplier = int(num2[i]) - 48;
            carry = 0;
            for (j = n1 - 1; j >= 0; j--) {
                temp = (int(num1[j]) - 48) * multiplier;
                neo = (int(ans[i+j+1]) - 48) + temp + carry;
                ans[i+j+1] = digits[neo % 10];
                carry = neo/10; 
            }
            ans[i] = digits[(int(ans[i]) - 48) + carry];
        }
        i = 0;
        while (ans[i] == '0')
            i++;
        for (j = i; j < n1 + n2; j++)
            result += ans[j];
        if (result.length() == 0)
            return "0";
        return result;
    }
};
