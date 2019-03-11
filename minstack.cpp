class MinStack {
private:
    stack<pair<int,int>> S;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (S.empty() || x < S.top().second)
            S.push(make_pair(x,x));
        else 
            S.push(make_pair(x,S.top().second));        
    }
    
    void pop() {
        S.pop();
    }
    
    int top() {
        return S.top().first;
    }
    
    int getMin() {
        return S.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
