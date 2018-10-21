class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int count = 0, i = 0;
        while (count < n) {
            int curr = i;
            int prev = nums[i];
            do {
                int next = (curr + k) % n;
                int temp = nums[next];
                nums[next] = prev;
                prev = temp;
                curr = next;
                count++;
            } while (i != curr);
            i++;
        }
    }
};
