class Solution {
public:
    void reverseString(vector<char>& s) {
        reverser(s,0,s.size()-1);        
    }
    
    void reverser(vector<char>& s, int l, int r) {
        if (l < r) {
            char tmp = s[l];
            s[l] = s[r];
            s[r] = tmp;
            reverser(s,l+1,r-1);
        }
    }
};
