class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> htable;
        int count = 0;
        int i,j;
        for (i = 0; i < nums.size(); i++)
            htable[nums[i]]++;
        vector <vector <int> > bucket(nums.size() + 1);
        for (auto h:htable) {
            bucket[h.second].push_back(h.first);
        }
        vector <int> ans;
        for (i = nums.size(); i >= 0; i--) {
            if (bucket[i].size() > 0 && count < k) {
                j = 0;
                while (count < k && j < bucket[i].size()) {
                    ans.push_back(bucket[i][j]);
                    j++;
                    count++;
                }
            }
        }
        return ans;
    }
};
