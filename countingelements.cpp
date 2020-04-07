class Solution {
public:
    int countElements(vector<int>& arr) {
        int ans = 0;
        vector<int> freqs(1001,0);
        for (int &x : arr)
            freqs[x]++;
        for (int &x : arr) {
            if (x < 1000 && freqs[x+1]) 
                ans++;
        }
        return ans;
    }
};
