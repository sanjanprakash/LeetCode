class Solution {
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        int i,j;
        int temp;
        vector<int> ans;
        for (i = 0; i < 10; i++)
            ans.push_back(i);
        if (N > 1) {
            ans.erase(ans.begin());
            N--;
            while (N > 0) {
                for (i = ans.size(); i > 0; i--) {
                    temp = ans[0];
                    ans.erase(ans.begin());
                    for (j = 0; j < 10; j++) {
                        if (abs((temp % 10) - j) == K)
                            ans.push_back(10*temp + j);
                    }
                }
                N--;
            }
        }
        return ans;
    }
};
