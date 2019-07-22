class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string S) {
        int num_lines = 0, last = 0;
        if (S.length()) {
            num_lines++;
            for (auto &x : S) {
                last += widths[x-'a'];
                if (last > 100) {
                    num_lines++;
                    last = widths[x-'a'];
                }
            }
        }
        return {num_lines,last};
    }
};
