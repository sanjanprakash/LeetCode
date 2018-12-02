class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        if (deck.size() == 1)
            return deck;
        stack<int>D;
        vector<int> ans;
        sort(deck.begin(),deck.end());
        int i;
        for (i = 0; i < deck.size(); i++)
            D.push(deck[i]);
        ans.push_back(D.top());
        D.pop();
        ans.insert(ans.begin(),D.top());
        D.pop();
        while (!D.empty()) {
            ans.insert(ans.begin(),ans[ans.size() - 1]);
            ans.pop_back();
            ans.insert(ans.begin(),D.top());
            D.pop();
        }
        return ans;
    }
};
