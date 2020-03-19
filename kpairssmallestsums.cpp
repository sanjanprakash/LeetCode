class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int i = 0, j = 0;
        pair<int, pair<int,int> > temp;
        vector<vector<int> > ans;
        set<pair<int,int> > unique;
        priority_queue<pair<int, pair<int,int> >, vector<pair<int, pair<int,int> > >, greater<pair<int, pair<int,int> > > > q;
        if (nums1.size() && nums2.size()) {
            q.push({nums1[0]+nums2[0], {0,0}});
            while (k && (i < nums1.size()-1 || j < nums2.size()-1)) {
                temp = q.top();
                q.pop();
                if (unique.find(temp.second) == unique.end()) {
                    i = temp.second.first;
                    j = temp.second.second;
                    ans.push_back({nums1[i],nums2[j]});
                    unique.insert({i,j});
                    if (i+1 < nums1.size())
                        q.push({nums1[i+1]+nums2[j],{i+1,j}});
                    if (j+1 < nums2.size())
                        q.push({nums1[i]+nums2[j+1],{i,j+1}});
                    k--;
                }
            }
        }
        return ans;
    }
};
