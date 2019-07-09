class Solution {
public:
    int calculate(string s) {
        int i, n = 0;
        int ans = 0;
        bool add = true;
        stack<pair<int,bool> > nums;
        for (i = 0; i < s.length(); i++) {
            if (s[i] == ' ')
                continue;
            else {
                if (s[i]-'0' >= 0 && s[i]-'0' <= 9) {
                    n *= 10;
                    n += s[i]-'0';
                }
                else if (s[i] == '+' || s[i] == '-') {
                    ans = add ? ans+n : ans-n;
                    add = s[i] == '+' ? true : false;
                    n = 0;
                }
                else if (s[i] == '(') {
                    nums.push(make_pair(ans,add));
                    add = true;
                    ans = 0;
                }
                else {
                    ans = add ? ans+n : ans-n;
                    ans = nums.top().second ? ans : -ans;
                    ans += nums.top().first;
                    nums.pop();
                    n = 0;
                }
            }
        }
        if (n) 
            ans = add ? ans+n : ans-n;
        return ans;
    }
};
