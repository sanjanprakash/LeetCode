class Solution {
public:
    static bool compare(pair<int,char> A, pair<int,char> B) {
        return A.first > B.first;
    }
    
    string frequencySort(string s) {
        int i, j = 0, n = s.length();
        string ans = "";
        vector<pair<int,char> > chars;
        unordered_map<char,int> freqs;
        unordered_map<char,int>::iterator it;
        for (i = 0; i < n; i++)
            freqs[s[i]]++;
        for (it = freqs.begin(); it != freqs.end(); it++) 
            chars.push_back(make_pair(it->second,it->first));
        sort(chars.begin(),chars.end(),compare);
        for (i = 0; i < n; i++) {
            ans += chars[j].second;
            chars[j].first--;
            if (chars[j].first == 0)
                j++;
        }
        return ans;
    }
};
