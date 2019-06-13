class RecentCounter {
private:
    queue<int> Q;
public:
    RecentCounter() {
            
    }
    
    int ping(int t) {
        Q.push(t);
        while (Q.front() < t-3000)
            Q.pop();
        return Q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */
