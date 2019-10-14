class Solution {
public:
    bool isPalindrome(string &s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            start++;
            end--;
        }
        return true;
    }
    
    void helper(string &s, int start, vector<string> &uno, vector<vector<string> > &ans) {
        int i, n = s.length();
        if (start == n)
            ans.push_back(uno);
        else {
            for (i = 0; i < n-start; i++) {
                if (isPalindrome(s,start,start+i)) {
                    uno.push_back(s.substr(start,i+1));
                    helper(s,start+i+1,uno,ans);
                    uno.pop_back();
                }
            }
        }
    }
    
    vector<vector<string>> partition(string s) {
        vector<string> uno;
        vector<vector<string> > ans;
        helper(s,0,uno,ans);
        return ans;
    }
};
