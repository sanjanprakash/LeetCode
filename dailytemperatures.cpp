class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        int n = T.size();
        int i, j;
        vector<int> arr(n, 0);
        for (i = n-1; i >= 0; i--) {
            j = i+1;
            while (j < n && T[j] <= T[i]) {
                if (arr[j] > 0)
                    j += arr[j];
                else
                    j = n;
            }
            if (j < n)
                arr[i] = j-i;   
        }
        return arr;
    }
};
