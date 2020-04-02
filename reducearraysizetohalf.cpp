class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n = arr.size();
        int ans = 0, deleted = 0;
        unordered_map<int,int> freqs;
        priority_queue<int, vector<int> > pq;
        for (int x : arr)
            freqs[x]++;
        for (auto &x : freqs)
            pq.push(x.second);
        while (deleted < n/2) {
            deleted += pq.top();
            pq.pop();
            ans++;
        }
        return ans;
    }
};
