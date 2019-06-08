class Solution {
public:
    char findTheDifference(string s, string t) {
        int i;
        char ans = 0;
        for (i = 0; i < s.length(); i++)
            ans = ans^s[i];
        for (i = 0; i < t.length(); i++) 
            ans = ans^t[i];
        return ans;
    }
};
