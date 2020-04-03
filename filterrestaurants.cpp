class Solution {
private:
    struct Compare {
        bool operator()(pair<int, int>  &A, pair<int, int> &B) {
            if (A.second == B.second)
                return A.first > B.first;
            return A.second > B.second;
        }
    };
    
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        int i, n = restaurants.size();
        vector<int> ans;
        vector<pair<int,int> > filtered;
        for (auto &x : restaurants) {
            if (veganFriendly && !x[2]) 
                continue;
            if (x[3] <= maxPrice && x[4] <= maxDistance)
                filtered.push_back({x[0],x[1]});
        }
        sort(filtered.begin(), filtered.end(), Compare());
        for (auto &x : filtered) 
            ans.push_back(x.first);
        return ans;
    }
};
