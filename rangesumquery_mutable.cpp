class NumArray {
private:
    vector<int> cumsum;
public:
    NumArray(vector<int>& nums) {
        int i;
        cumsum.push_back(0);
        for (i = 0; i < nums.size(); i++)
            cumsum.push_back(nums[i]+cumsum[i]);
    }
    
    void update(int i, int val) {
        int diff = cumsum[i+1] - cumsum[i] - val;
        i++;
        while (i < cumsum.size()) {
            cumsum[i] -= diff;
            i++;
        }
    }
    
    int sumRange(int i, int j) {
        return cumsum[j+1]-cumsum[i];    
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(i,val);
 * int param_2 = obj->sumRange(i,j);
 */
