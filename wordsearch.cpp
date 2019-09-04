class Solution {
public:
    bool DFS(vector<vector<char>>& board, vector<vector<bool>>& visited, pair<int,int> curr, string &word, int id) {
        int x = curr.first, y = curr.second;
        int r = board.size(), c = board[0].size();
        if (id == word.length())
            return true;
        visited[x][y] = true;
        if (x+1 < r && !visited[x+1][y] && board[x+1][y] == word[id] && DFS(board,visited,{x+1,y},word,id+1)) 
                return true;
        if (y+1 < c && !visited[x][y+1] && board[x][y+1] == word[id] && DFS(board,visited,{x,y+1},word,id+1))
                return true;
        if (x-1 > -1 && !visited[x-1][y] && board[x-1][y] == word[id] && DFS(board,visited,{x-1,y},word,id+1))
                return true;
        if (y-1 > -1 && !visited[x][y-1] && board[x][y-1] == word[id] && DFS(board,visited,{x,y-1},word,id+1))
            return true;
        visited[x][y] = false;
        return false;
    }    
    
    bool exist(vector<vector<char>>& board, string word) {
        int i,j;
        int r = board.size(), c = board[0].size();
        vector<vector<bool> > visited(r,vector<bool>(c,false));
        for (i = 0; i < r; i++) {
            for (j = 0; j < c; j++) {
                if (board[i][j] == word[0] && DFS(board,visited,{i,j},word,1))
                    return true;
            }
        }
        return false;
    }
};
