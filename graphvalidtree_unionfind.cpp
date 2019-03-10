class Solution {
private:
    vector<int> parent;
public:
    int Find(int idx) {
        if (parent[idx] == -1)
            return idx;
        parent[idx] = Find(parent[idx]);
        return parent[idx];
    }
    
    void Union(int a, int b) {
        int par_a = Find(a);
        int par_b = Find(b);
        parent[par_a] = par_b;
    }
    
    bool validTree(int n, vector<pair<int, int>>& edges) {
        parent = vector<int>(n,-1);
        if (edges.size() != n-1)
            return false;
        int i;
        int start,end;
        int par_s, par_e;
        for (i = 0; i < n-1; i++) {
            start = edges[i].first;
            end = edges[i].second;
            par_s = Find(start);
            par_e = Find(end);
            if (par_s == par_e)
                return false;
            Union(start,end);
        }
        return true;
    }
};
