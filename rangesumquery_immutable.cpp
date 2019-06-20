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
    
    int sumRange(int i, int j) {
        return cumsum[j+1]-cumsum[i];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(i,j);
 */
