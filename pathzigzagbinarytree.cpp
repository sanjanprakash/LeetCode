
class Solution {
public:
    vector<int> pathInZigZagTree(int label) {
        int i;
        int level = 0, temp = label;
        bool first = true;
        vector<long long int> lplusr;
        lplusr.push_back(0);
        lplusr.push_back(1);
        lplusr.push_back(5);
        for (i = 2; i < 25; i++)
            lplusr.push_back(2*lplusr[i]+1);
        while (temp > 0) {
            temp /= 2;
            level++;
        }
        vector<int> ans(level,1);
        while (level > 1) {
            if (first)
                ans[level-1] = label;
            if (level%2 == 0) 
                label = lplusr[level] - label;
            if (!first) {
                ans[level-1] = label;
                if (level%2 == 0)
                    label = lplusr[level] - label;
            }
            label /= 2;
            level--;
            first = false;
        }
        return ans;
    }
};
