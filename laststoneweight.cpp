class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int x,y;
        make_heap(stones.begin(),stones.end());
        while (stones.size() > 1) {
            y = stones.front();
            pop_heap(stones.begin(),stones.end());
            stones.pop_back();
            x = stones.front();
            pop_heap(stones.begin(),stones.end());
            stones.pop_back();
            if (x != y) {
                stones.push_back(y-x);
                push_heap(stones.begin(),stones.end());
            }
        }
        return stones.size() ? stones.front() : 0;
    }
};
