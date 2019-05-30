class Solution {
public:
    int heightChecker(vector<int>& heights) {
        int i;
        int curr = 0, ans = 0;
        map<int,int> height_freqs;
        for (i = 0; i < heights.size(); i++) 
            height_freqs[heights[i]]++;
        for (i = 0; i < heights.size(); i++) {
            while (height_freqs[curr] == 0)
                curr++;
            if (curr != heights[i])
                ans++;
            height_freqs[curr]--;
        }
        return ans;
    }
};
