class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int i,j;
        int r = board.size(), c;
        pair<int,int> pred;
        queue<pair<int,int> > Q;
        vector<vector<int> > dir = {{1,0},{0,1},{-1,0},{0,-1}};
        if (r > 1) {
            c = board[0].size();
            if (c > 1) {
                for (i = 0; i < r; i++) {
                    if (board[i][0] == 'O') {
                        Q.push(make_pair(i,0));
                        board[i][0] = '-';
                    }
                    if (board[i][c-1] == 'O') {
                        Q.push(make_pair(i,c-1));
                        board[i][c-1] = '-';
                    }
                }
                for (i = 0; i < c; i++) {
                    if (board[0][i] == 'O') {
                        Q.push(make_pair(0,i));
                        board[0][i] = '-';
                    }
                    if (board[r-1][i] == 'O') {
                        Q.push(make_pair(r-1,i));
                        board[r-1][i] = '-';
                    }
                }
                while (!Q.empty()) {
                    pred = Q.front();
                    Q.pop();
                    for (i = 0; i < 4; i++) {
                        if (pred.first+dir[i][0] >= 0 && pred.first+dir[i][0] < r && pred.second+dir[i][1] >= 0 && pred.second+dir[i][1] < c) {
                            if (board[pred.first+dir[i][0]][pred.second+dir[i][1]] == 'O') {
                                board[pred.first+dir[i][0]][pred.second+dir[i][1]] = '-';
                                Q.push(make_pair(pred.first+dir[i][0],pred.second+dir[i][1]));
                            }
                        }
                    }
                }
                for (i = 0; i < r; i++) {
                    for (j = 0; j < c; j++) {
                        if (board[i][j] == 'O')
                            board[i][j] = 'X';
                        else if (board[i][j] == '-')
                            board[i][j] = 'O';
                    }
                }
            }
        }
    }
};
