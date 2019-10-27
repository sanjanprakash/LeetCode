class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        int x,y,ans = 0;
        priority_queue<int,vector<int>,greater<int> > pq;
        for (auto &x : sticks)
            pq.push(x);
        while (pq.size() > 1) {
            x = pq.top();
            pq.pop();
            y = pq.top();
            pq.pop();
            ans += x+y;
            pq.push(x+y);
        }
        return ans;
    }
};
