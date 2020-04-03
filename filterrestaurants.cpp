class Solution {
private:
    struct Compare {
        bool operator()(vector<int>  &A, vector<int> &B) {
            if (A[1] == B[1])
                return A[0] > B[0];
            return A[1] > B[1];
        }
    };
    
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
        int i, n = restaurants.size();
        vector<int> ans;
        sort(restaurants.begin(), restaurants.end(), Compare());
        for (auto &x : restaurants) {
            if (veganFriendly && !x[2]) 
                continue;
            if (x[3] <= maxPrice && x[4] <= maxDistance)
                ans.push_back(x[0]);
        }
        return ans;
    }
};
