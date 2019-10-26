class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int i = 0, n = nums.size();
        vector<int> ans;
        deque<int> increasing;
        if (n) {
            while (i < n) {
                while (!increasing.empty() && i-k >= increasing.front())
                    increasing.pop_front();
                while (!increasing.empty() && nums[i] >= nums[increasing.back()])
                    increasing.pop_back();
                increasing.push_back(i);
                if (i >= k-1)
                    ans.push_back(nums[increasing.front()]);
                i++;
            }
        }
        return ans;
    }
};
