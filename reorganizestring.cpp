class Solution {
public:
    static bool compare(pair<int,char> A, pair<int,char> B) {
        return A.first > B.first;
    }
    
    string reorganizeString(string S) {
        int i, j = 0, n = S.length();
        vector<pair<int,char> > freqs;
        string ans = S;
        for (i = 0; i < 26; i++)
            freqs.push_back(make_pair(0,97+i));
        for (i = 0; i < n; i++) {
            freqs[S[i]-'a'].first++;
            if (freqs[S[i]-'a'].first > (n+1)/2)
                return "";
        }
        sort(freqs.begin(),freqs.end(),compare);
        i = 0;
        while (i < n) {
            ans[i] = freqs[j].second;
            freqs[j].first--;
            i += 2;
            if (!freqs[j].first)
                j++;
        }
        i = 1;
        while (i < n) {
            ans[i] = freqs[j].second;
            freqs[j].first--;
            i += 2;
            if (!freqs[j].first)
                j++;
        }
        return ans;
    }
};
