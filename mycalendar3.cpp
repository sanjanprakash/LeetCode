class MyCalendarThree {
private:
    map<int,int>  times;    
public:
    MyCalendarThree() {
        
    }
    
    int book(int start, int end) {
        int i, ans = -1, sum = 0;
        times[start]++;
        times[end]--;
        for (auto x : times) {
            sum += x.second;
            ans = max(ans,sum);
        }
        return ans;
    }
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
