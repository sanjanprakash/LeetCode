class Solution {
public:
    
    int BS(vector<int>&arr,int l,int r,int key) {
        int mid = l + (r - l)/2;
        if (l <= r) {
            if (arr[mid] == key)
                return mid;
            else if (arr[mid] < key)
                return BS(arr,mid + 1,r,key);
            else
                return BS(arr,l,mid - 1,key);
        }
        return -1;
    }
    
    vector<int> twoSum(vector<int>& nums, int target) {
        int comp,i,n = nums.size();
        vector<int>ans;
        for (i = 0; i < n; i++) {
            comp = BS(nums,0,n - 1,target - nums[i]);
            if (comp == i)
                comp == -1;
            if (comp != -1)
                break;
        }
        if (comp != -1) {
            ans.push_back(i);
            ans.push_back(comp);
        }
        return ans;
    }
};
