class Solution {
public:
    int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
        int i, n = distance.size();
        int forward = 0, reverse = 0;
        i = start;
        while (i != destination) {
            forward += distance[i];
            i = (i+1)%n;
        }
        i = destination;
        while (i != start) {
            reverse += distance[i];
            i = (i+1)%n;
        }
        return min(forward,reverse);
    }
};
