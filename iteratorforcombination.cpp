class CombinationIterator {
private:
    set<string> allPerms;
    set<string>::iterator it;
public:
    void getAllPermutations(string text, int k) {
        int i, n = text.length();
        int idx, currMask;
        int maxMask = 1 << n;
        string perm;
        for (currMask = 1; currMask <= maxMask; currMask++) {
            idx = currMask;
            i = 0;
            perm = "";
            while (i < n && idx) {
                if (idx&1)
                    perm += text[i];
                idx >>= 1;
                i++;
            }
            if (perm.length() == k)
                allPerms.insert(perm);
        }
    }
    
    CombinationIterator(string characters, int combinationLength) {
        getAllPermutations(characters, combinationLength);
        it = allPerms.begin();
    }
    
    string next() {
        return *it++;
    }
    
    bool hasNext() {
        return it != allPerms.end();
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
