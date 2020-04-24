class LRUCache {
public:
    int cap;
    list<pair<int, int> >recent;
    unordered_map<int,list<pair<int, int> >::iterator > X;
    
    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (X.find(key) == X.end())
            return -1;
        else {
            auto p = X[key];
            int val = p->second;
            recent.erase(p);
            recent.push_front({key, val});
            X[key] = recent.begin();
            return val;
        }
    }
    
    void put(int key, int value) {
        if (X.find(key) != X.end()) {
            auto p = X[key];
            recent.erase(p);
        }
        else {
            if (X.size() == cap) {
                auto least_recent = recent.rbegin();
                X.erase(least_recent->first);
                recent.pop_back();
            }
        }
        recent.push_front({key, value});
        X[key] = recent.begin();
    }
};


/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
