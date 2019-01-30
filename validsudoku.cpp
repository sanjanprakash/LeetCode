class Solution {
public:
    bool colCheck(vector<vector<char> > board, int col) {
        int i;
        int *arr = new int[9];
        for (i = 0; i < 9; i++)
            arr[i] = 0;
        for (i = 0; i < 9; i++) {
            if (board[i][col] != '.') {
                if (arr[board[i][col]-'1'] == 1)
                    return false;
                else
                    arr[board[i][col]-'1']++;
            }
        }
        return true;
    }
    
    bool rowCheck(vector<vector<char> > board, int row) {
        int i;
        int *arr = new int[9];
        for (i = 0; i < 9; i++)
            arr[i] = 0;
        for (i = 0; i < 9; i++) {
            if (board[row][i] != '.') {
                if (arr[board[row][i]-'1'] == 1)
                    return false;
                else
                    arr[board[row][i]-'1']++;
            }
        }
        return true;
    }
    
    bool boxCheck(vector<vector<char> > board, int row, int col) {
        int i,j;
        int *arr = new int[9];
        for (i = 0; i < 9; i++)
            arr[i] = 0;
        for (i = 0; i < 3; i++) {
            for (j = 0; j < 3; j++) {
                if (board[row+i][col+j] != '.') {
                    if (arr[board[row+i][col+j]-'1'] == 1)
                        return false;
                    else
                        arr[board[row+i][col+j]-'1']++;
                }
            }
        }
        return true;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
        int i,j;
        for (i = 0; i < 9; i++) {
            if (!colCheck(board,i))
                return false;
        }
        for (i = 0; i < 9; i++) {
            if (!rowCheck(board,i))
                return false;
        }
        for (i = 0; i < 9; i += 3) {
            for (j = 0; j < 9; j += 3) {
                if (!boxCheck(board,i,j))
                    return false;
            }
        }
        return true;
    }
};
