class Solution {
public:
    int toNum(char x) {
        return int(x) - 48;
    }
    
    int numDecodings(string s) {
        int n = s.length(), i, num = toNum(s[0]), dig;
        int *arr = new int[n];
        arr[0] = num == 0 ? 0 : 1;
        for (i = 1; i < n; i++) {
            dig = toNum(s[i]);
            num = ((num % 10)*10) + dig;
            if (dig == 0 && (num > 26 || num == 0))
                return 0;
            if (num <= 26) {
                if (dig == 0)
                    arr[i] = arr[i-1];
                else if (num < 10)
                    arr[i] = arr[i-1];
                else {
                    if (i > 1)
                        arr[i] = arr[i-1] + arr[i-2];
                    else
                        arr[i] = arr[i-1] + 1;
                }
            }
            else
                arr[i] = arr[i-1];
        }
        if (n > 2) {
            if (s[n-1] == '0')
                return arr[n-3];
        }
        return arr[n-1];
    }
};
