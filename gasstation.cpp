class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int i;
        int start = 0, n = gas.size();
        int curr = gas[0]-cost[0], total = gas[0]-cost[0];
        for (i = 1; i < n; i++) {
            if (curr < 0) {
                curr = 0;
                start = i;
            }
            curr += gas[i]-cost[i];
            total += gas[i]-cost[i];
        }
        return total < 0 ? -1 : start;
    }
};
