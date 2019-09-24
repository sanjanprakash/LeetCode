class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> visited_columns(n,false);
        vector<string> grid(n,string(n,'.'));
        vector<vector<string> > ans;
        dfs(grid,visited_columns,ans,n);
        return ans.size();
    }
    
    void dfs(vector<string>& grid, vector<bool>& visited, vector<vector<string> >& ans, int n) {
        int i, dim = grid[0].length();
        if (!n) {
            ans.push_back(grid);
            return;
        }
        for (i = 0; i < dim; i++) {
            if (!visited[i] && queen_possible(grid,n-1,i)) {
                visited[i] = true;
                grid[n-1][i] = 'Q';
                dfs(grid,visited,ans,n-1);
                grid[n-1][i] = '.';
                visited[i] = false;
            }
        }        
    }
    
    bool queen_possible(vector<string>& grid, int row, int col) {
        int n = grid[0].length();
        int l = col, r = col;
        while (row < n) {
            if (l >= 0 && grid[row][l] == 'Q')
                return false;
            if (r < n && grid[row][r] == 'Q')
                return false;
            if (grid[row][col] == 'Q')
                return false;
            row++;
            l--;
            r++;
        }
        return true;        
    }
};
