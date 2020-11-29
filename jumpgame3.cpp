class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size(), curr;
        vector<bool> visited(n, false);
        queue<int> Q;
        Q.push(start);
        while (!Q.empty()) {
            curr = Q.front();
            Q.pop();
            visited[curr] = true;
            if (arr[curr] == 0)
                return true;
            if (curr-arr[curr] >= 0 && !visited[curr-arr[curr]])
                Q.push(curr-arr[curr]);
            if (curr+arr[curr] < n && !visited[curr+arr[curr]])
                Q.push(curr+arr[curr]);
        }
        return false;
    }
};
