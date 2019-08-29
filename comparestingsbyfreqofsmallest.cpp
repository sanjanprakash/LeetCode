class Solution {
public:
    int f(string& s) {
        char smallest = '{';
        unordered_map<char,int> freqs;
        for (auto &x : s) {
            if (x < smallest)
                smallest = x;
            freqs[x]++;
        }
        return freqs[smallest];
    }
    
    vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
        int n = words.size();
        vector<int> scores, ans;
        for (auto &x : words)
            scores.push_back(f(x));
        sort(scores.begin(),scores.end());
        for (auto &x : queries) 
            ans.push_back(distance(upper_bound(scores.begin(),scores.end(),f(x)),scores.end()));
        return ans;
    }
};
