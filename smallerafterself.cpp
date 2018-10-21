class Solution {
public:
    void Mergesort(vector<int>& nums, int l, int r, vector<int>& ind, vector<int>& ans) {
        int m = l + (r - l)/2;
        if (l < r) {
            Mergesort(nums, l, m, ind, ans);
            Mergesort(nums, m+1, r, ind, ans);
            Merge(nums, l, m, m+1, r, ind, ans);
        }
    }
    
    void Merge(vector<int>& nums, int ll, int lr, int rl, int rr, vector<int>& ind, vector<int>& ans) {
        int start = ll;
        int *temp = new int[rr-ll+1];
        int i, j = 0, count = 0;
        while (ll <= lr || rl <= rr) {
            if (ll > lr) {
                temp[j] = ind[rl];
                j++;
                rl++;
            }
            else if (rl > rr) {
                ans[ind[ll]] += count;
                temp[j] = ind[ll];
                j++;
                ll++;
            }
            else if (nums[ind[ll]] > nums[ind[rl]]) {
                temp[j] = ind[rl];
                j++;
                rl++;
                count++;
            }
            else {
                ans[ind[ll]] += count;
                temp[j] = ind[ll];
                j++;
                ll++;
            }
        }
        for (i = 0; i < rr-start+1; i++)
            ind[start+i] = temp[i];
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int i;
        vector<int> ans, ind, res;
        for (i = 0; i < nums.size(); i++) {
            res.push_back(0);
            ind.push_back(i);
        }
        Mergesort(nums,0,nums.size()-1,ind,res);
        for (int i : res) {
            ans.push_back(i);
        }
        return ans;
    }
};
