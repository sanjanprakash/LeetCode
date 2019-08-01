class Solution {
public:
    pair<int,int> position(char& x) {
        int r = (x-'a')/5;
        int c = (x-'a')%5;
        return {r,c};
    }
    
    string alphabetBoardPath(string target) {
        string ans = "";
        pair<int,int> curr = {0,0}, next;
        for (auto &x : target) {
            next = position(x);
            if (curr.first == 5 && x != 'z') {
                while (next.first < curr.first) {
                    ans += "U";
                    curr.first--;
                }
                while (next.first > curr.first) {
                    ans += "D";
                    curr.first++;
                }
                while (next.second < curr.second) {
                    ans += "L";
                    curr.second--;
                }
                while (next.second > curr.second) {
                    ans += "R";
                    curr.second++;
                }
            }
            else {
                while (next.second < curr.second) {
                    ans += "L";
                    curr.second--;
                }
                while (next.second > curr.second) {
                    ans += "R";
                    curr.second++;
                }
                while (next.first < curr.first) {
                    ans += "U";
                    curr.first--;
                }
                while (next.first > curr.first) {
                    ans += "D";
                    curr.first++;
                }
            }
            ans += "!";
        }
        return ans;
    }
};
