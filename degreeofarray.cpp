class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int i;
        int max = -1, min = INT_MAX, mode;
        int num, start, end, count;
        map<int,pair<pair<int,int>,int> > freqs;
        map<int,pair<pair<int,int>,int> >::iterator it;
        for (i = 0; i < nums.size(); i++) {
            if (freqs.find(nums[i]) != freqs.end()) {
                start = freqs[nums[i]].first.first;
                count = freqs[nums[i]].second;
                freqs[nums[i]] = make_pair(make_pair(start,i),count+1);
            }
            else
                freqs[nums[i]] = make_pair(make_pair(i,i),1);
        }
        for (it = freqs.begin(); it != freqs.end(); it++) {
            num = it->first;
            start = it->second.first.first;
            end = it->second.first.second;
            count = it->second.second;
            if (max <= count) {
                if (max < count || min > end - start) {
                    min = end - start;
                    max = count;
                    mode = num;
                }
            }
        }
        return min+1;
    }
};
