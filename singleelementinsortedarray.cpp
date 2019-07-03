class Solution {
public:
    int singleFind(vector<int> arr, int l, int r) {
        int m = l + (r-l)/2;
        if (l < r) {
            if (m > 0 && arr[m] == arr[m-1]) {
                if (m%2)
                    return singleFind(arr,m+1,r);
                return singleFind(arr,l,m-1);
            }
            if (m < arr.size()-1 && arr[m] == arr[m+1]) {
                if (m%2)
                    return singleFind(arr,l,m-1);
                return singleFind(arr,m+1,r);
            }
        }
        return arr[m];
    }
    
    int singleNonDuplicate(vector<int>& nums) {
        return singleFind(nums,0,nums.size()-1);
    }
};
