class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int move = 0, n = s.length();
        for (auto &x : shift)
            move = x[0] ? move + x[1] : move - x[1];
        if (move < 0) {
            move = (abs(move)%n);
            return s.substr(move,n) + s.substr(0,move);
        }
        else {
            move = move%n;
            return s.substr(n-move,n) + s.substr(0,n-move);
        }
    }
};
