class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 < n2)
            return findMedianSortedArrays(nums2,nums1);
        
        int l = 0, h = 2*n2;
        while (l <= h) {
            double l1 = INT_MIN, l2 = INT_MIN, r1 = INT_MAX, r2 = INT_MAX;
            int mid2 = (l + h)/2;
            int mid1 = n1 + n2 - mid2;
            if (mid1 != 0)
                l1 = nums1[(mid1 - 1)/2];
            if (mid2 != 0)
                l2 = nums2[(mid2 - 1)/2];
            if (mid1 != 2*n1)
                r1 = nums1[mid1/2];
            if (mid2 != 2*n2)
                r2 = nums2[mid2/2];
            if (l1 > r2)
                l = mid2 + 1;
            else if (l2 > r1)
                h = mid2 - 1;
            else
                return (max(l1,l2) + min(r1,r2))/2;
        }
        return 0;
    }
};
