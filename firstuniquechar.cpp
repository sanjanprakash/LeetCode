class Solution {
public:
    int firstUniqChar(string s) {
        int *arr = new int[26];
        int i;
        int ans = -1;
        for (i = 0; i < 26; i++)
            arr[i] = 0;
        for (i = 0; i < s.length(); i++)
            arr[s[i]-'a']++;
        for (i = 0; i < s.length(); i++) {
            if (arr[s[i]-'a'] == 1)
                return i;
        }
        return -1;
    }
};
