class Solution {
private:
    int n;
    vector<int> prefix;
public:
    Solution(vector<int>& w) {
        int i, j, m = w.size();
        prefix.push_back(w[0]);
        for (i = 1; i < m; i++) 
            prefix.push_back(prefix[i-1] + w[i]);
        n = prefix[prefix.size()-1];
    }
    
    int pickIndex() {
        return upper_bound(prefix.begin(), prefix.end(), rand()%n) - prefix.begin();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
