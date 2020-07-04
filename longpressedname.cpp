class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int m = name.length(), n = typed.length();
        int i = 1, j = 1;
        if (name[0] == typed[0]) {
            while (i < m && j < n) {
                if (name[i] == typed[j]) {
                    i++;
                    j++;
                }
                else {
                    while (typed[j] == typed[j-1])
                        j++;
                    if (name[i] != typed[j])
                        break;
                }
            }
            while (typed[j] == typed[j-1])
                j++;
            return i == m && j == n;
        }
        return false;
    }
};
