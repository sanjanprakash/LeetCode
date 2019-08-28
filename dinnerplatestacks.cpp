class DinnerPlates {
private :
    int max_cap;
    set<int> leftmost;
    map<int,stack<int> > S;
public :
    DinnerPlates(int capacity) {
        max_cap = capacity;
    }
    
    void push(int val) {
        if (leftmost.empty())
            leftmost.insert(S.size());
        auto it = leftmost.begin();
        int next_push = *it;
        S[next_push].push(val);
        if (S[next_push].size() == max_cap)
            leftmost.erase(it);
    }
    
    int pop() {
        if (!S.size())
            return -1;
        return popAtStack(S.rbegin()->first);
    }
    
    int popAtStack(int index) {
        int ans = -1;
        if (S.find(index) != S.end()) {
            ans = S[index].top();
            S[index].pop();
            leftmost.insert(index);
            if (S[index].empty())
                S.erase(index);
        }
        return ans;
    }
};

/**
 * Your DinnerPlates object will be instantiated and called as such:
 * DinnerPlates* obj = new DinnerPlates(capacity);
 * obj->push(val);
 * int param_2 = obj->pop();
 * int param_3 = obj->popAtStack(index);
 */
