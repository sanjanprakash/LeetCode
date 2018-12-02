class Solution {
public:
    string timer(vector<int> inp) {
        string ans = "";
        int h = 10*inp[0] + inp[1];
        int m = 10*inp[2] + inp[3];
        if (h <= 23 && m <= 59)
            ans += to_string(inp[0]) + to_string(inp[1]) + ":" + to_string(inp[2]) + to_string(inp[3]);
        return ans;
    }
    
    string largestTimeFromDigits(vector<int>& A) {
        sort(A.begin(),A.end());
        string ans = timer(A), temp;
        while (next_permutation(A.begin(),A.end())) {
            temp = timer(A);
            if (temp != "")
                ans = max(ans,temp);
        }
        return ans;
    }
};
