class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        int mod = 1000000007;
        vector<long long int> h_diff, v_diff;
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        h_diff.push_back(horizontalCuts[0]%mod);
        v_diff.push_back(verticalCuts[0]%mod);
        for (int i = 1; i < horizontalCuts.size(); i++) {
            h_diff.push_back((horizontalCuts[i]-horizontalCuts[i-1])%mod);
        }
        h_diff.push_back((h-horizontalCuts[horizontalCuts.size()-1])%mod);
        for (int i = 1; i < verticalCuts.size(); i++) {
            v_diff.push_back((verticalCuts[i]-verticalCuts[i-1])%mod);
        }
        v_diff.push_back((w-verticalCuts[verticalCuts.size()-1])%mod);
        sort(h_diff.begin(), h_diff.end(), greater<int>());
        sort(v_diff.begin(), v_diff.end(), greater<int>());
        return ((long long int)h_diff[0]*(long long int)v_diff[0])%mod;
    }
};
