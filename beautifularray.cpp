class Solution {
public:
    vector<int> beautifulArray(int N) {
        vector<int>ans;
        int i;
        ans.push_back(1);
        while (ans.size() < N) {
            vector<int>temp;
            for (i = 0; i < ans.size(); i++) {
                if (2*ans[i] - 1 <= N)
                    temp.push_back(2*ans[i] - 1);
            }
            for (i = 0; i < ans.size(); i++) {
                if (2*ans[i] <= N)
                    temp.push_back(2*ans[i]);
            }
            ans = temp;
        }
        return ans;
    }
};
