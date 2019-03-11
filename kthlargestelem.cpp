class Solution {
public:
    int partition(vector<int> &nums, int l, int r) {
        int i,j = l;
        int size = r-l;
        int pivot_idx = rand() % (size+1);
        swap(nums[r],nums[l+pivot_idx]);
        int pivot = nums[r];
        for (i = l; i < r; i++) {
            if (nums[i] <= pivot) {
                swap(nums[i],nums[j]);
                j++;
            }
        }
        swap(nums[j],nums[r]);
        return j;
    }
    
    int kthSmallestHelper(vector<int> &nums, int l, int r, int k) {
        if (0 < k && k <= r-l+1) {
            int pivot = partition(nums,l,r);
            if (pivot-l == k-1)
                return nums[pivot];
            if (pivot-l > k-1)
                return kthSmallestHelper(nums,l,pivot-1,k);
            else
                return kthSmallestHelper(nums,pivot+1,r,k-pivot+l-1);
        }
        return INT_MAX;
    }
    
    int findKthLargest(vector<int>& nums, int k) {
        int asc_order = nums.size() - k + 1;
        return kthSmallestHelper(nums,0,nums.size()-1,asc_order);
    }
};
