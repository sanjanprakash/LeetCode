class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int i,j;
        vector<int> ans;
        map<int,int> places;
        for (i = 0; i < nums2.size(); i++)
            places[nums2[i]] = i;
        for (i = 0; i < nums1.size(); i++) {
            for (j = places[nums1[i]] + 1; j < nums2.size(); j++) {
                if (nums2[j] > nums1[i]) {
                    ans.push_back(nums2[j]);
                    break;
                }
            }
            if (j == nums2.size())
                ans.push_back(-1);
        }
        return ans;
    }
};
