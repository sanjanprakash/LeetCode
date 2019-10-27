/*
// Definition for an Interval.
class Interval {
public:
    int start;
    int end;

    Interval() {}

    Interval(int _start, int _end) {
        start = _start;
        end = _end;
    }
};
*/
class Solution {
public:
    vector<Interval*> employeeFreeTime(vector<vector<Interval*>> schedule) {
        int prev;
        map<int,int> endPoints;
        map<int,int>::iterator it;
        vector<Interval *> ans;
        for (auto &x : schedule) {
            for (auto &y : x) {
                endPoints[y->start]++;
                endPoints[y->end]--;
            }
        }
        it = endPoints.begin();
        prev = it->second;
        it++;
        while (it != endPoints.end()) {
            it->second += prev;
            prev = it->second;
            it++;
        }
        it = endPoints.begin();
        while (it != endPoints.end()) {
            if (it->second == 0) {
                Interval *neo = new Interval;
                neo->start = it->first;
                while (it != endPoints.end() && it->second == 0) 
                    it++;
                if (it->first > neo->start) {
                    neo->end = it->first;
                    ans.push_back(neo);
                }
            }
            else
                it++;
        }
        return ans;
    }
};
