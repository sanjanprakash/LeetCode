class Solution {
public:
    string convert(string s, int numRows) {
        string *arr = new string[numRows];
        string ans = "";
        bool flag = false;
        int i,j;
        if (numRows == 1 || numRows >= s.length())
            return s;
        for (i = 0; i < numRows; i++)
            arr[i] = s[i];
        while (flag == false) {
            if ((i - 1) % (numRows - 1) == 0 && (i - 1)/(numRows - 1) % 2 == 1) {
               for (j = numRows - 2; j >= 0; j--) {
                   arr[j] += s[i];
                   i++;
                   if (i == s.length()) {
                       flag = true;
                       break;
                   }
               }
            }
            if (flag == true)
                break;
            if ((i - 1) % (numRows - 1) == 0 && (i - 1)/(numRows - 1) % 2 == 0) {
               for (j = 1; j < numRows; j++) {
                   arr[j] += s[i];
                   i++;
                   if (i == s.length()) {
                       flag = true;
                       break;
                   }
               }
            }
        }
        for (i = 0; i < numRows; i++)
            ans += arr[i];
        return ans;
    }
};
