class HitCounter {
private:
    queue<int> Q;
public:
    /** Initialize your data structure here. */
    HitCounter() {

    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        Q.push(timestamp);
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int start = timestamp - 300;
        while (Q.front() <= start && Q.size() > 0) 
            Q.pop();
        return Q.size();
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */
