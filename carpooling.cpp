bool sorter(pair<int,int> A, pair<int,int> B) {
    return A.first == B.first ? A.second < B.second : A.first < B.first;
}

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int i, sum = 0;
        vector<pair<int,int> > arr;
        for (i = 0; i < trips.size(); i++) {
            arr.push_back(make_pair(trips[i][1],trips[i][0]));
            arr.push_back(make_pair(trips[i][2],-trips[i][0]));
        }
        sort(arr.begin(),arr.end(),sorter);
        for (i = 0; i < arr.size(); i++) {
            sum += arr[i].second;
            if (sum > capacity)
                return false;
        }
        return true;
    }
};
