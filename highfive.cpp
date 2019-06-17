class Solution {
public:
    vector<vector<int>> highFive(vector<vector<int>>& items) {
        int i, j, sum;
        vector<vector<int> > ans;
        map<int,vector<int> > sorter;
        map<int,vector<int> >::iterator it;
        for (i = 0; i < items.size(); i++) {
            j = 0;
            while (j < sorter[items[i][0]].size() && items[i][1] > sorter[items[i][0]][j])
                j++;
            if (sorter[items[i][0]].size() < 5 || j != 0)
                sorter[items[i][0]].insert(sorter[items[i][0]].begin()+j,items[i][1]);
            if (sorter[items[i][0]].size() > 5)                
                sorter[items[i][0]].erase(sorter[items[i][0]].begin());
        }
        for (it = sorter.begin(); it != sorter.end(); it++) {
            sum = 0;
            vector<int> uno;
            for (i = 0; i < 5; i++)
                sum += it->second[i];
            uno.push_back(it->first);
            uno.push_back(sum/5);
            ans.push_back(uno);
        }
        return ans;
    }
};
