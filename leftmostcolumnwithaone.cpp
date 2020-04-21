/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> dims = binaryMatrix.dimensions();
        int i = 0, j = dims[1]-1;
        int ans = -1;
        while (i < dims[0] && j > -1) {
            if (binaryMatrix.get(i,j)) {
                ans = j;
                j--;
            }
            else
                i++;
        }
        return ans;
    }
};
