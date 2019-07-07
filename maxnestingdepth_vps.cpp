class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int i;
        int open_a = 0, open_b = 0;
        vector<int> ans;
        for (i = 0; i < seq.length(); i++) {
            if (seq[i] == '(') {
                if (!open_a && !open_b) {
                    open_a++;
                    ans.push_back(0);
                }
                else if (open_a && !open_b) {
                    open_b++;
                    ans.push_back(1);
                }
                else if (!open_a && open_b) {
                    open_a++;
                    ans.push_back(0);
                }
                else {
                    if (open_b < open_a) {
                        open_b++;
                        ans.push_back(1);
                    }
                    else {
                        open_a++;
                        ans.push_back(0);
                    }
                }
            }
            else {
                if (open_a && !open_b) {
                    open_a--;
                    ans.push_back(0);
                }
                else if (!open_a && open_b) {
                    open_b--;
                    ans.push_back(1);
                }
                else {
                    open_b--;
                    ans.push_back(1);
                }
            }
        }
        return ans;
    }
};
