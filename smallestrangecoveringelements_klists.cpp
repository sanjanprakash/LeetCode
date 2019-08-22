class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        int i, k = nums.size(), smallest = INT_MAX;
        int l,r;
        pair<int,int> s,b;
        vector<int> curr(k,0), sizes, ans(2,-1);
        set<pair<int,int> > range;
        for (i = 0; i < k; i++) {
            sizes.push_back(nums[i].size());
            range.insert({nums[i][0],i});
        }
        while (1) {
            s = *(range.begin());
            b = *(range.crbegin());
            l = min(s.first,b.first);
            r = max(s.first,b.first);
            if (smallest >= r-l) {
                ans[0] = smallest == r-l ? min(l,ans[0]) : l;
                ans[1] = ans[0] == l ? r : ans[1]; 
                smallest = r-l;
            }
            range.erase(range.begin());
            curr[s.second]++;
            if (curr[s.second] == sizes[s.second])
                break;
            range.insert({nums[s.second][curr[s.second]],s.second});
        }
        return ans;
    }
};
