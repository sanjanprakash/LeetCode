class ExamRoom {
public:
    int n;
    set<int> seats;
    ExamRoom(int N) {
        n = N;
    }
    
    int seat() {
        int max_dist, neo_pos;
        int curr,prev;
        set<int>::iterator it = seats.begin();
        if (seats.empty()) {
            seats.insert(0);
            return 0;
        }
        max_dist = *it ? *it : INT_MIN; 
        neo_pos = *it ? 0 : -1;
        prev = *it;
        it++;
        for (; it != seats.end(); it++) {
            curr = *it;
            if ((curr-prev)/2 > max_dist) {
                max_dist = (curr-prev)/2;
                neo_pos = prev + max_dist;
            }
            prev = curr;
        }
        neo_pos = prev != n-1 && n-1-prev > max_dist ? n-1 : neo_pos;
        seats.insert(neo_pos);
        return neo_pos;
    }
    
    void leave(int p) {
        seats.erase(p);
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */
