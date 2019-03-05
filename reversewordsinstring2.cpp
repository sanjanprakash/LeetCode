class Solution {
public:
    void reverser(vector<char> &str, int l, int r) {
        while (l < r) {
            swap(str[l],str[r]);
            l++;
            r--;
        }
    }
    void reverseWords(vector<char>& str) {
        int i = 0, l = 0, n = str.size();
        reverser(str,0,n-1);
        while (i < n) {
            if (str[i] == ' ') {
                reverser(str,l,i-1);
                l = i+1;
            }
            i++;
        }
        reverser(str,l,i-1);
    }
};
