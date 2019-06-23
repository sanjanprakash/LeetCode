/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length(), mid, l = 0, r = n-1, m;
        while (l <= r) {
            mid = l + (r-l)/2;
            if (mid > 0 && mid < n && mountainArr.get(mid) > mountainArr.get(mid-1) && mountainArr.get(mid) > mountainArr.get(mid+1))
                break;
            else if (mountainArr.get(mid) < mountainArr.get(mid+1))
                l = mid+1;
            else
                r = mid-1;
        }
        if (target > mountainArr.get(mid))
            return -1;
        else if (target == mountainArr.get(mid))
            return mid;
        else {
            l = 0;
            r = mid-1;
            while (l <= r) {
                m = l + (r-l)/2;
                if (mountainArr.get(m) == target)
                    return m;
                else if (mountainArr.get(m) < target)
                    l = m+1;
                else
                    r = m-1;
            }
            l = mid+1;
            r = n-1;
            while (l <= r) {
                m = l + (r-l)/2;
                if (mountainArr.get(m) == target)
                    return m;
                else if (mountainArr.get(m) < target)
                    r = m-1;
                else
                    l = m+1;
            }
            return -1;
        }
    }
};
