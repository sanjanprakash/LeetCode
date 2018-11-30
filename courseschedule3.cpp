class Solution {
public:
    
    static bool Compare(pair<int,int> &A, pair<int,int> &B) {
        return A.second < B.second;
    }
    
    int scheduleCourse(vector<vector<int>>& courses) {
        vector<pair<int,int> > courses_pairs;
        int i, n = courses.size();
        int ans = 0, days = 0;
        for (i = 0; i < n; i++) {
            courses_pairs.push_back({courses[i][0],courses[i][1]});
        }
        sort(courses_pairs.begin(), courses_pairs.end(), Compare);
        priority_queue<int> Q;
        for (i = 0; i < n; i++) {
            Q.push(courses_pairs[i].first);
            days += courses_pairs[i].first;
            ans++;
            if (days > courses_pairs[i].second) {
                ans--;
                days -= Q.top();
                Q.pop();
            }
        }
        return ans;
    }
};
