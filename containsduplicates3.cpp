class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int i, n = nums.size();
        int bucket;
        unordered_map<int, int> buckets;
        if (n == 0 || t < 0)
            return false;
        for (i = 0; i < n; i++) {
            bucket = nums[i]/((long)t+1);
            if (nums[i] < 0)
                bucket--;
            if (buckets.find(bucket) != buckets.end())
                return true;
            else {
                buckets[bucket] = nums[i];
                if (buckets.find(bucket+1) != buckets.end() && (long)buckets[bucket+1]-nums[i] <= t)
                    return true;
                if (buckets.find(bucket-1) != buckets.end() && (long)nums[i]-buckets[bucket-1] <= t)
                    return true;
                if (i >= k) {
                    bucket = nums[i-k]/((long)t+1);
                    if (nums[i-k] < 0)
                        bucket--;
                    buckets.erase(bucket);
                }
            }
        }
        return false;
    }
};
