class FirstUnique {
private:
    list<int> L;
    unordered_map<int, int> freqs;
    unordered_map<int, list<int>::iterator> loc_map;
public:
    FirstUnique(vector<int>& nums) {
        for (int &x : nums) {
            cout << x << " ";
            freqs[x]++;
            if (freqs[x] == 1) 
                loc_map[x] = L.insert(L.end(), x);
            else if (freqs[x] == 2)
                L.erase(loc_map[x]);
        }
    }
    
    int showFirstUnique() {
        if (L.empty())
            return -1;
        return L.front();
    }
    
    void add(int value) {
        freqs[value]++;
        if (freqs[value] == 1)
            loc_map[value] = L.insert(L.end(), value);
        else if (freqs[value] == 2)
            L.erase(loc_map[value]);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
