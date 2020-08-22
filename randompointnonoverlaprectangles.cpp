class Solution {
private:
    int n;
    vector<int> cum_area;
    vector<vector<int>> rects;
public:
    Solution(vector<vector<int>>& rects) {
        int area_sum = 0;
        this->rects = rects;
        n = rects.size();
        for (auto &single : rects) {
            area_sum += (single[2]-single[0]+1)*(single[3]-single[1]+1);
            cum_area.push_back(area_sum);
        } 
    }
    
    vector<int> pick() {
        int random_area = rand()%cum_area[n-1];
        int idx = upper_bound(cum_area.begin(), cum_area.end(), random_area) - cum_area.begin();
        int width = rects[idx][2]-rects[idx][0];
        int height = rects[idx][3]-rects[idx][1];
        int x = rand()%(width+1);
        int y = rand()%(height+1);
        return {rects[idx][0]+x, rects[idx][1]+y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
