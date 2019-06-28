class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int i;
        string str;
        vector<vector<string> > ans;
        map<string,vector<string> > groups;
        map<string,vector<string> >::iterator it;
        for (i = 0; i < strs.size(); i++) {
            str = strs[i];
            sort(str.begin(),str.end());
            groups[str].push_back(strs[i]);
        }
        for (it = groups.begin(); it != groups.end(); it++)
            ans.push_back(it->second);
        return ans;
    }
};
