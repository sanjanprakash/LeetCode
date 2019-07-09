class MyCalendar {
private:
    map<int,int> times;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        int sum = 0;
        times[start]++;
        times[end]--;
        for (auto x : times) {
            sum += x.second;
            if (sum == 2) {
                times[start]--;
                times[end]++;
                return false;
            }
        }
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
