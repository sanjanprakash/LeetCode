class Solution {
private:
    static bool compare(vector<int> &A, vector<int> &B) {
        if (A[0] == B[0])
            return A[1] < B[1];
        return A[0] >= B[0];
    }
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int> > ans;
        sort(people.begin(), people.end(), compare);
        for (auto &x : people)
            ans.insert(ans.begin() + x[1], x);
        return ans;
    }
};
