class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        int i;
        vector<int> ans;
        vector<pair<int,int> > matrix(arr1.size());
        unordered_map<int,int> arr2_keys;
        for (i = 0; i < arr2.size(); i++) 
            arr2_keys[arr2[i]] = i;
        for (int i = 0; i < arr1.size(); i++) {
            if (arr2_keys.find(arr1[i]) != arr2_keys.end()) 
                matrix[i] = {arr2_keys[arr1[i]],arr1[i]};
            else
                matrix[i] = {INT_MAX,arr1[i]};
        }
        sort(matrix.begin(),matrix.end());
        for (auto &x : matrix)
            ans.push_back(x.second);
        return ans;
    }
};
