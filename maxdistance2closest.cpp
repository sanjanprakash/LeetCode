class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int i = 0, n = seats.size();
        int ans, curr, prev;
        while (!seats[i])
            i++;
        ans = seats[0] ? INT_MIN : i;
        prev = i;
        while (1) {
            while (i < n && !seats[i])
                i++;
            if (i == n)
                break;
            ans = max(ans,(i-prev)/2);
            prev = i;
            i++;
        }
        ans = seats[n-1] ? ans : max(n-1-prev,ans);
        return ans;
    }
};
