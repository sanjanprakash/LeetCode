class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i, num = flowerbed.size();
        int count = 0;
        for (i = 0; i < num; i++) {
            if (!flowerbed[i] && (!i || !flowerbed[i-1]) && (i==num-1 || !flowerbed[i+1])) {
                flowerbed[i] = 1;
                count++;
            }
        }
        return count >= n;
    }
};
