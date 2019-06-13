class MedianFinder {
private:
    int size;
    int min,max;
    priority_queue<int> max_pq;
    priority_queue<int,vector<int>, greater<int> > min_pq;
public:
    /** initialize your data structure here. */
    MedianFinder() {
        min = 0;
        max = 0;
        size = 0;
    }
    
    void addNum(int num) {
        int shift;
        if (!size || num > min_pq.top()) {
            min_pq.push(num);
            min++;
        }
        else {
            max_pq.push(num);
            max++;
        }
        if (max-min > 1) {
            shift = max_pq.top();
            max_pq.pop();
            min_pq.push(shift);
            max--;
            min++;
        }
        else if (min-max > 1) {
            shift = min_pq.top();
            min_pq.pop();
            max_pq.push(shift);
            min--;
            max++;
        }
        size++;
    }
    
    double findMedian() {
        if (size%2) 
            return max > min ? double(max_pq.top()) : double(min_pq.top());
        return double(max_pq.top()+min_pq.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
