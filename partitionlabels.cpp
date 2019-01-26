class Solution {
public:
    vector<int> partitionLabels(string S) {
        vector<int> ans;
        int i;
        int start = -1, end = 0;
        int *first = new int[26], *last = new int[26];
        for (i = 0; i < 26; i++) {
            first[i] = -1;
            last[i] = -1;
        }
        for (i = 0; i < S.length(); i++) {
            if (first[S[i]-'a'] == -1)
                first[S[i]-'a'] = i;
            last[S[i]-'a'] = i;
        }
        i = 0;
        start = first[S[0]-'a'];
        end = last[S[0]-'a'];
        while (end < S.length() && i < S.length()) {
            if (first[S[i]-'a'] > start && first[S[i]-'a'] < end && last[S[i]-'a'] > end) 
                end = last[S[i]-'a'];            
            if (i == end || start == end) {
                end++;
                ans.push_back(end - start);
                start = end;
                if (i+1 < S.length()) 
                    end = last[S[i+1]-'a'];
            }
            i++;
        }
        return ans;
    }
};
