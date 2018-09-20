class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s == "")
            return 0;
        int *last = new int[256];
        int i;
        int curr = 1, prev, max = 1;
        for (i = 0; i < 256; i++)
            last[i] = -1;
        last[int(s[0])] = 0;
        for (i = 1; i < s.length(); i++) {
            prev = last[int(s[i])];
            if (prev == -1 || i - prev > curr)
                curr++;
            else {
                if (curr > max)
                    max = curr;
                curr = i - prev;
            }
            last[int(s[i])] = i;
        }
        if (curr > max)
            max = curr;
        return max;
    }
};
