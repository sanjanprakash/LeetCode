class TreeAncestor {
private:
    vector<vector<int> > parents;
public:
    TreeAncestor(int n, vector<int>& parent) 
    : parents(n, vector<int> (16, -1)) {
        int i, j;
        for (i = 0; i < parent.size(); i++) {
            parents[i][0] = parent[i];
            for (j = 1; j < 16; j++) {
                if (parents[i][j-1] != -1)
                    parents[i][j] = parents[parents[i][j-1]][j-1];
            }
        }
        
    }
    
    int getKthAncestor(int node, int k) {
        int i, ans = node;
        for (i = 15; i >= 0; i--) {
            if (parents[ans][i] != -1 && pow(2, i) <= k) {
                ans = parents[ans][i];
                k -= pow(2, i);
            }
        }
        return k ? -1 : ans;
    }
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
