class Solution {
public:
    int myAtoi(string str) {
        long long int i, ans = 0;
        int non_space = 0;
        bool no_digit = true, exceed = false;
        int multiplier = 1;
        for (i = 0; i < str.length(); i++) {
            if (int(str[i]) != 32)
                non_space++;
            if (non_space > 0 && str[i] == ' ')
                return ans*multiplier;
            if (str[i] == '-' && no_digit)
                multiplier = -1;
            else if (int(str[i]) < 58 && int(str[i]) > 47) {
                no_digit = false;
                if (ans >= 214748365) {
                    exceed = true;
                    return multiplier == 1 ? INT_MAX : INT_MIN;
                }
                else if (ans == 214748364 && int(str[i]) > 55 && multiplier == -1)
                    return INT_MIN;
                else if (ans == 214748364 && int(str[i]) > 54 && multiplier == 1)
                    return INT_MAX;
                ans *= 10;
                ans += int(str[i]) - 48;
            }
            if (non_space == 2 && no_digit == true) 
                return 0;
            else if (str[i] != ' ' && (str[i] != '+' && str[i] != '-') && no_digit)
                return 0;
            else if (!no_digit && (int(str[i]) > 57 || int(str[i]) < 48))
                return ans*multiplier;
        }
        return ans*multiplier;
    }
};
