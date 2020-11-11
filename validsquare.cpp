class Solution {
public:
    double length(vector<int>& s1, vector<int>& s2) {
        return sqrt(pow(s1[0]-s2[0], 2) + pow(s1[1]-s2[1], 2));
    }
    
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        map<double, int> freqs;
        freqs[length(p1, p2)]++;
        freqs[length(p1, p3)]++;
        freqs[length(p1, p4)]++;
        freqs[length(p2, p3)]++;
        freqs[length(p2, p4)]++;
        freqs[length(p3, p4)]++;
        if (freqs.size() != 2)
            return false;
        if (freqs.begin()->second == 2 && freqs.rbegin()->second == 4)
            return true;
        if (freqs.begin()->second == 4 && freqs.rbegin()->second == 2)
            return true;
        return false;
    }
};
