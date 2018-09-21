class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0,j = n - 1;
        int ans = 0,area;
        while (i != j) {
            if (height[i] < height[j]) {
                area = height[i] * (j - i);
                if (area > ans)
                    ans = area;
                i++;
            }
            else {
                area = height[j] * (j - i);
                if (area > ans)
                    ans = area;
                j--;
            }
        }
        return ans;
    }
};
