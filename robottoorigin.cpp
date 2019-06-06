class Solution {
public:
    bool judgeCircle(string moves) {
        int i;
        int hsum = 0, vsum = 0;
        for (i = 0; i < moves.length(); i++) {
            if (moves[i] == 'L')
                hsum--;
            else if (moves[i] == 'R')
                hsum++;
            else if (moves[i] == 'U')
                vsum++;
            else
                vsum--;
        }
        return hsum == 0 && vsum == 0;
    }
};
