class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int arr[n];
        arr[0] = 1;
        int i, j;
        int count = 1, ans;
        int lis_i;
        for (i = 1; i < n; i++) {
            lis_i = INT_MIN;
            for (j = 0; j < i; j++) {
                if (nums[i] > nums[j]) 
                    lis_i = max(lis_i,arr[j]);
            }
            if (lis_i == INT_MIN)
                arr[i] = 1;
            else
                arr[i] = 1 + lis_i;
        }
        for (i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
        ans = arr[0];
        for (i = 1; i < n; i++) {
            if (ans < arr[i])
                ans = arr[i];
        }
        return ans;
    }
};
