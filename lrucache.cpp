class LRUCache {
public:
    unordered_map<int,int> X;
    int cap;
    deque<int>recent;
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (X.find(key) == X.end())
            return -1;
        else 
            recent.erase(remove(recent.begin(), recent.end(), key), recent.end());
        recent.push_back(key);
        return X[key];
    }
    
    void put(int key, int value) {
        int least_recent;
        if (X.size() == cap && X.find(key) == X.end()) {
            least_recent = recent.front();
            recent.pop_front();
            X.erase(least_recent);
        }
        else {
            recent.erase(remove(recent.begin(), recent.end(), key), recent.end());
        }
        recent.push_back(key);
        X[key] = value;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
