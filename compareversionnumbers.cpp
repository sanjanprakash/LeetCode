class Solution {
public:
    int strToNum(string str, int l, int r) {
        int i = l;
        int ans = 0;
        while (str[i] == '0' && i <= r)
            i++;
        if (i <= r) {
            while (i <= r) {
                ans = 10*ans + (str[i] - '0');
                i++;
            }
        }
        return ans;
    }
    
    vector<int> breaker(string str) {
        int l = 0;
        int i = 0;
        int temp;
        vector<int> ans;
        while (i < str.length()) {
            if (str[i] == '.') {
                temp = strToNum(str,l,i-1);
                ans.push_back(temp);
                l = i+1;
            }
            i++;
        }
        temp = strToNum(str,l,i-1);
        ans.push_back(temp);
        return ans;
    }
    
    int compareVersion(string version1, string version2) {
        vector<int> a,b;
        int i, diff;
        a = breaker(version1);
        b = breaker(version2);
        diff = a.size()-b.size();
        if (diff < 0) {
            for (i = 0; i < -diff; i++)
                a.push_back(0);
        }
        if (diff > 0) {
            for (i = 0; i < diff; i++)
                b.push_back(0);
        }
        i = 0;
        while (i < a.size()) {
            if (a[i] < b[i])
                return -1;
            else if (a[i] > b[i]) 
                return 1;
            i++;
        }
        return 0;
    }
};
