struct Compare {
    bool operator()(vector<int>& A, vector<int>& B) {
        if (A[2] == 0 && B[2] == 0 && A[0] == B[0])
            return A[1] >= B[1];
        if (A[2] == 1 && B[2] == 1 && A[0] == B[0])
            return A[1] <= B[1];
        if (A[2] == 0 && B[2] == 1 && A[0] == B[0])
            return A[2] < B[2];
        return A[0] <= B[0];
    }   
};

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        int highest = 0;
        vector<vector<int> > points, ans;
        map<int,int> heights;
        heights[0] = 1;
        for (auto &x : buildings) {
            points.push_back({x[0],x[2],0});
            points.push_back({x[1],x[2],1});
        }
        sort(points.begin(),points.end(),Compare());
        for (auto &x : points) {
            if (x[2] == 0) {
                heights[x[1]]++;
                if (heights.rbegin()->first != highest) {
                    highest = heights.rbegin()->first;
                    ans.push_back({x[0],highest});
                }
            }
            else {
                heights[x[1]]--;
                if (!heights[x[1]])
                    heights.erase(x[1]);
                if (heights.rbegin()->first != highest) {
                    highest = heights.rbegin()->first;
                    ans.push_back({x[0],highest});
                }
            }
        }
        return ans;
    }
};
