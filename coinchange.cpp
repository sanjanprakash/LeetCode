class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int k = coins.size();
        int arr[amount + 1];
        int i,j,sub_ans;
        for (i = 0; i <= amount; i++)
            arr[i] = INT_MAX;
        arr[0] = 0;
        for (i = 1; i <= amount; i++) {
            for (j = 0; j < k; j++) {
                if (coins[j] <= i) {
                    sub_ans = arr[i - coins[j]];
                    if (sub_ans != INT_MAX)
                        arr[i] = min(arr[i],1 + sub_ans);
                }   
            } 
        }
        if (arr[amount] == INT_MAX)
            return -1;
        return arr[amount];
    }
};
