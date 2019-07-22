class MyHashSet {
private:
    bool *hash;
public:
    /** Initialize your data structure here. */
    MyHashSet() {
        int i;
        hash = new bool[1000001];
        for (i = 0; i <= 1000000; i++)
            hash[i] = false;
    }
    
    void add(int key) {
        hash[key] = true;
    }
    
    void remove(int key) {
        hash[key] = false;
    }
    
    /** Returns true if this set contains the specified element */
    bool contains(int key) {
        return hash[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
