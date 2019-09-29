class Solution {
public:
    string removeDuplicates(string s, int k) {
        char curr;
        string ans = "";
        stack<pair<char,int> > pile;
        for (auto &x : s) {
            if (pile.empty() || x != pile.top().first) 
                pile.push({x,k-1});
            else
                pile.push({x,pile.top().second-1});
            if (!pile.top().second) {
                curr = pile.top().first;
                while (!pile.empty() && pile.top().first == curr)
                    pile.pop();
            }
        }
        while (!pile.empty()) {
            ans += pile.top().first;
            pile.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
