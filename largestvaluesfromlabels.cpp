bool sorter(pair<int,int> A, pair<int,int> B) {
    return A.second > B.second;
}

class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        int i;
        int ans = 0;
        vector<pair<int,int> > items;
        map<int,int> log;
        for (i = 0; i < values.size(); i++)
            items.push_back(make_pair(labels[i],values[i]));
        sort(items.begin(),items.end(),sorter);
        i = 0;
        while (i < items.size() && num_wanted) {
            if (log[items[i].first] < use_limit) {
                log[items[i].first]++;
                num_wanted--;
                ans += items[i].second;
            }
            i++;
        }
        return ans;
    }
};
