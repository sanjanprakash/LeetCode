class TNode {
public:
    bool isEnd;
    TNode *kids[26];
    
    TNode() {
        int i;
        isEnd = false;
        for (i = 0; i < 26; i++)
            kids[i] = NULL;
    }
    
    void getNode(TNode *root, int id) {
        root->kids[id] = new TNode();
    }
    
    void insert(string &key) {
        int id;
        TNode *move = this;
        for (auto &x : key) {
            id = x-'a';
            if (!move->kids[id])
                getNode(move,id);
            move = move->kids[id];
        }
        move->isEnd = true;
    }
};

class Trie {
private:
    TNode *root;
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TNode;
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        root->insert(word);
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        int id;
        TNode *move = root;
        for (auto &x : word) {
            id = x-'a';
            if (!move->kids[id])
                return false;
            move = move->kids[id];
        }
        return move->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        int id;
        TNode *move = root;
        for (auto &x : prefix) {
            id = x-'a';
            if (!move->kids[id])
                return false;
            move = move->kids[id];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
