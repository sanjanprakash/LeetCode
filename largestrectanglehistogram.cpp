class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int j = 1, n = heights.size();
        int ans = 0;
        pair<int,int> last;
        stack<pair<int,int> > S;
        if (n) {
            heights.push_back(-1);
            ans = heights[0];
            S.push({0,0});
            while (j <= n) {
                last = {-1,-1};
                while (!S.empty() && heights[S.top().first] > heights[j]) {
                    last = S.top();
                    S.pop();
                    ans = max(ans,(j-last.second)*heights[last.first]);
                }
                if (last.first == -1)
                    S.push({j,j});
                else
                    S.push({j,last.second});
                j++;
            }
        }
        return ans;
    }
};
