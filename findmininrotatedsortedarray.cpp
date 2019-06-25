class Solution {
public:
    int findPivot(vector<int> arr, int l, int r) {
        if (l < r) {
            int m = l + (r-l)/2;
            if (arr[l] > arr[l+1])
                return l;
            if (arr[r] > arr[l])
                return r;
            if (arr[m] > arr[m-1] && arr[m] > arr[m+1])
                return m;
            if (arr[l] > arr[m])
                return findPivot(arr,l,m-1);
            return findPivot(arr,m+1,r);
            
        }
        return 0;
    }
    
    int findMin(vector<int>& nums) {
        return nums[(findPivot(nums,0,nums.size()-1)+1)%nums.size()]; 
    }
};
