class Solution {
public:
    int reversePairs(vector<int>& nums) {
        return MergeSort(nums,0,nums.size());
    }
    
    int MergeSort(vector<int>& nums, int l, int r) {
        int ans = 0, i;
        if (l < r-1) {
            int mid = (r+l)/2;
            ans = MergeSort(nums, l, mid);
            ans += MergeSort(nums, mid, r);
            ans += Merge(nums, l, mid, r);
        }
        return ans;
    }
    
    int Merge(vector<int>& nums, int l, int m, int r) {
        vector<int> sorted;
        int count = 0;
        int k;
        int i = l, j;
        for (j = m; i != m; i++) {
            for (; j != r && 0.5 * (nums[i]) > (nums[j]); j++);
            count += j - m;
        }
        i = l;
        j = m;
        while (i < m && j < r) {
            if (nums[i] <= nums[j]) {
                sorted.push_back(nums[i]);
                i++;
            }
            else {
                sorted.push_back(nums[j]);
                j++;
            }
        }
        while (i < m) {
            sorted.push_back(nums[i]);
            i++;
        }
        while (j < r) {
            sorted.push_back(nums[j]);
            j++;
        }
        j = l;
        for (i = 0; i < sorted.size(); i++) {
            nums[j] = sorted[i];
            j++;
        }
        return count;
    }
};
