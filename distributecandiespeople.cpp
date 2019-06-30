class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int i = 0, n = num_people;
        int candy = 1, total = 0;
        vector<int> num(n,0);
        while (total < candies) {
            num[i%n] += min(candy,candies-total);
            total += candy;
            candy++;
            i++;
        }
        return num;
    }
};
