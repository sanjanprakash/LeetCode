class Solution {
public:
    string toHex(long long int num) {
        char hex[16] = {'0','1','2','3','4','5','6','7','8','9','a','b','c','d','e','f'};
        if (num < 0)
            num = 4294967295 + (num+1);
        string ans = "";
        while (num) {
            ans = hex[num%16] + ans;
            num /= 16;
        }
        return ans == "" ? "0" : ans;
    }
};
