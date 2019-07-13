class FreqStack {
private:
    unordered_map<int,int> freqs;
    vector<int> nums;
public:
    FreqStack() {
        
    }
    
    void push(int x) {
        freqs[x]++;
        nums.push_back(x);
    }
    
    int pop() {
        int i, max = -1;
        int to_delete;
        for (auto x : freqs) {
            if (x.second > max) 
                max = x.second;
        }
        for (i = nums.size()-1; i >= 0; i--) {
            if (freqs[nums[i]] == max) {
                to_delete = nums[i];
                freqs[nums[i]]--;
                nums.erase(nums.begin()+i);
                break;
            }
        }
        return to_delete;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 */
