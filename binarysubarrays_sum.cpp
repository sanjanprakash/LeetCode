class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int S) {
        int i, j, n = A.size();
        int ans = 0;
        int *arr = new int[n];
        arr[0] = A[0];
        if (S == 0) {
            i = 0;
            while (i < n) {
                while (A[i] == 1 && i < n)
                    i++;
                j = i;
                while (A[j] == 0 && j < n)
                    j++;
                ans += ((j-i)*(j-i+1))/2;
                i = j;
            }
        }
        else {
            for (i = 1; i < n; i++)
                arr[i] = arr[i-1] + A[i];
            int *count = new int[arr[n-1] + 1];
            for (i = 0; i <= arr[n-1]; i++)
                count[i] = 0;
            for (i = 0; i < n; i++)
                count[arr[i]]++;
            if (S > arr[n-1])
                return 0;
            if (arr[n-1] == 0)
                return (n*(n+1))/2;
            ans += count[S];
            for (i = 0; i <= arr[n-1]-S; i++)
                ans += count[i]*count[i+S];
        }
        return ans;    
    }
};
