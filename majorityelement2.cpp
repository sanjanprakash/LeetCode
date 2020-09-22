class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size(), cand1 = INT_MIN, cand2 = INT_MIN;
        int count1 = 0, count2 = 0;
        int fin_count1 = 0, fin_count2 = 0;
        for (int x : nums) {
            if (x == cand1)
                count1++;
            else if (x == cand2)
                count2++;
            else if (!count1) {
                cand1 = x;
                count1++;
            }
            else if (!count2) {
                cand2 = x;
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }
        for (int x : nums) {
            if (x == cand1)
                fin_count1++;
            else if (x == cand2)
                fin_count2++;
        }
        if (fin_count1 > n/3)
            ans.push_back(cand1);
        if (fin_count2 > n/3)
            ans.push_back(cand2);
        
        return ans;
    }
};
