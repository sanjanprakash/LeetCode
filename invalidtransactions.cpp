class Solution {
public:
    void parse(string& tx, int& a, int& t, string& n, string& p) {
        int i = 0, l = tx.length();
        while (tx[i] != ',') {
            n += tx[i];
            i++;
        }
        i++;
        while (tx[i] != ',') {
            t = 10*t + (tx[i]-'0');
            i++;
        }
        i++;
        while (tx[i] != ',') {
            a = 10*a + (tx[i]-'0');
            i++;
        }
        i++;
        while (i < l) {
            p += tx[i];
            i++;
        }
    }
    
    vector<string> invalidTransactions(vector<string>& transactions) {
        int i, j, l = transactions.size();
        int a, t;
        string n, p;
        vector<int> amt, time;
        vector<string> name, place, ans;
        vector<bool> included(l,false);
        for (i = 0; i < l; i++) {
            a = 0;
            t = 0;
            n = "";
            p = "";
            parse(transactions[i],a,t,n,p);
            amt.push_back(a);
            time.push_back(t);
            name.push_back(n);
            place.push_back(p);
            if (a > 1000) {
                included[i] = true;
                ans.push_back(transactions[i]);
            }
        }
        for (i = 0; i < l-1; i++) {
            for (j = i+1; j < l; j++) {
                if (name[i] == name[j] && (abs(time[i]-time[j]) <= 60) && place[i] != place[j]) {
                    if (!included[i]) {
                        ans.push_back(name[i]+","+to_string(time[i])+","+to_string(amt[i])+","+place[i]);
                        included[i] = true;
                    }
                    if (!included[j]) {
                        ans.push_back(name[j]+","+to_string(time[j])+","+to_string(amt[j])+","+place[j]);
                        included[j] = true;
                    }
                }
            }
        }
        return ans;
    }
};
