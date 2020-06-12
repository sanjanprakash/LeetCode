class RandomizedSet {
private:
    int n;
    vector<int> nums;
    unordered_map<int, int> indices;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        n = 0;
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (indices.find(val) == indices.end()) {
            nums.push_back(val);
            indices[val] = n;
            n++;
            return true;
        }
        return false;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        int temp, idx;
        if (indices.find(val) != indices.end()) {
            idx = indices[val];
            temp = nums[idx];
            nums[idx] = nums[n-1];
            nums.pop_back();
            indices[nums[idx]] = idx;
            indices.erase(val);
            n--;
            return true;
        }
        return false;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand()%n];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
