class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        int i = 0, j;
        int Rr, Rc;
        int ans = 4;
        bool flag = false;
        while (!flag) {
            for (j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    flag = true;
                    Rr = i;
                    Rc = j;
                    break;
                }
            }
            i++;
        }
        for (i = Rr + 1; i < 8; i++) {
            if (board[i][Rc] != '.' && board[i][Rc] != 'p') {
                ans--;
                break;
            }
            if (board[i][Rc] == 'p')
                break;
        }
        if (i == 8)
            ans--;
        for (i = Rr - 1; i > -1; i--) {
            if (board[i][Rc] != '.' && board[i][Rc] != 'p') {
                ans--;
                break;
            }
            if (board[i][Rc] == 'p')
                break;
        }
        if (i == -1)
            ans--;
        for (i = Rc + 1; i < 8; i++) {
            if (board[Rr][i] != '.' && board[Rr][i] != 'p') {
                ans--;
                break;
            }
            if (board[Rr][i] == 'p')
                break;
        }
        if (i == 8)
            ans--;
        for (i = Rc - 1; i > -1; i--) {
            if (board[Rr][i] != '.' && board[Rr][i] != 'p') {
                ans--;
                break;
            }
            if (board[Rr][i] == 'p')
                break;
        }
        if (i == -1)
            ans--;
        return ans;
    }
};
