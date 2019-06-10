class Solution {
public:
    vector<int> merge(vector<int> A, vector<int> B) {
        int i = 0, j = 0;
        vector<int> ans;
        while (i != A.size() && j != B.size()) {
            if (A[i] > B[j]) {
                ans.push_back(B[j]);
                j++;
            }
            else {
                ans.push_back(A[i]);
                i++;
            }
        }
        while (i != A.size()) {
            ans.push_back(A[i]);
            i++;
        }
        while (j != B.size()) {
            ans.push_back(B[j]);
            j++;
        }
        return ans;
    }
    
    vector<int> merge_sort(vector<int> &arr, int l, int r) {
        int m;
        vector<int> left, right, ans;        
        if (l < r) {
            m = l + (r-l)/2;
            left = merge_sort(arr,l,m);
            right = merge_sort(arr,m+1,r);
            ans = merge(left,right);
        }
        else if (l == r)
            ans.push_back(arr[l]);
        return ans;
    }
    
    vector<int> sortArray(vector<int>& nums) {
        return merge_sort(nums,0,nums.size()-1);
    }
};
