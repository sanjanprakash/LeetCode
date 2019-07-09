class MyCalendarTwo {
private:
    map<int,int> times;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        int sum = 0;
        times[start]++;
        times[end]--;
        for (auto x : times) {
            sum += x.second;
            if (sum >= 3) {
                times[start]--;
                times[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
