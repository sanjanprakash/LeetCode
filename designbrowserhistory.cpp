class BrowserHistory {
private:
    stack<string> f, b;
public:
    BrowserHistory(string homepage) {
        b.push(homepage);
    }
    
    void visit(string url) {
        while (!f.empty())
            f.pop();
        b.push(url);
    }
    
    string back(int steps) {
        while (b.size() != 1 && steps) {
            f.push(b.top());
            b.pop();
            steps--;
        }
        return b.top();
    }
    
    string forward(int steps) {
        string ans;
        if (f.empty())
            return b.top();
        while (!f.empty() && steps) {
            ans = f.top();
            b.push(ans);
            f.pop();
            steps--;
        }
        return ans;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
