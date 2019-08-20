class Solution {
public:
    string lastSubstring(string s) {
        int i = 0, j = 1, l = 0, n = s.length();
        string ans = "";
        while (i+l < n && j+l < n && l < n) {
            if (s[i+l] == s[j+l])
                l++;
            else {
                if (s[i+l] < s[j+l])
                    i += l+1;
                else 
                    j += l+1;
                if (i == j)
                    j++;
                l = 0;
            }            
        }
        for (l = min(i,j); l < n; l++)
            ans += s[l];
        return ans;
    }
};
