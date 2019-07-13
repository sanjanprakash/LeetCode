class Solution {
public:
    static bool compare(pair<int,string> a, pair<int,string> b) {
        return a.first == b.first ? a.second < b.second : a.first > b.first;
    }
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        vector<string> ans;
        vector<pair<int,string> > count;
        unordered_map<string,int> freqs;
        for (auto x : words)
            freqs[x]++;
        for (auto x : freqs)
            count.push_back({x.second,x.first});
        sort(count.begin(),count.end(),compare);
        for (auto x : count) {
            if (!k)
                break;
            else {
                ans.push_back(x.second);
                k--;
            }
        }
        return ans;
    }
};
