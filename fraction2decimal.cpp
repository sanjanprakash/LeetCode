class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long int n = numerator, d = denominator;
        string ans = "";
        bool found = false;
        map<int,int> quots;
        n = abs(n);
        d = abs(d);
        
        if (numerator && ((numerator < 0) ^ (denominator < 0)))
            ans = "-" + ans;
        ans += to_string(n/d);
        n = n%d;
        
        if (n)
            ans += ".";
        while (n && !found) {
            if (quots.find(n) == quots.end())
                quots[n] = ans.length();
            else {
                ans += ")";
                ans.insert(quots[n],"(");
                found = true;
                continue;
            }
            n *= 10;
            ans += to_string(n/d);
            n = n%d;
        }
        return ans;
    }
};
