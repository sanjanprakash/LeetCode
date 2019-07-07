class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        int i, j;
        vector<int> diff(n+2,0);
        vector<int> arr;
        for (i = 0; i < bookings.size(); i++) {
            diff[bookings[i][0]] += bookings[i][2];
            diff[bookings[i][1]+1] -= bookings[i][2];
        }
        arr.push_back(diff[1]);
        for (i = 2; i <= n; i++)
            arr.push_back(diff[i] + arr[i-2]);
        return arr;
    }
};
