class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int k = coins.size();
        int arr[amount + 1];
        int i,j,sub_ans;
        int picks[amount + 1];
        for (i = 0; i <= amount; i++) {
            arr[i] = INT_MAX;
            picks[i] = -1;
        }
        arr[0] = 0;
        for (i = 1; i <= amount; i++) {
            for (j = 0; j < k; j++) {
                if (coins[j] <= i) {
                    sub_ans = arr[i - coins[j]];
                    if (sub_ans != INT_MAX && arr[i] > 1 + sub_ans) {
                        arr[i] = 1 + sub_ans;
                        picks[i] = j;
                    }
                }   
            } 
        }
        i = amount;
        while (picks[i] != -1) {
            i = i - coins[picks[i]];
        }
        cout << endl;
        if (arr[amount] == INT_MAX)
            return -1;
        return arr[amount];
    }
    
    int numSquares(int n) {
        int i;
        vector<int>squares;
        for (i = 1; i*i <= n; i++)
            squares.push_back(i*i);
        
        return coinChange(squares,n);
    }
};
