class TNode {
private:
    vector<TNode*> children;
    bool end;
public:
    TNode() : children(26, NULL) {
        this->end = false;
    }
    
    void addChild(int child) {
        this->children[child] = new TNode();
    }
    
    TNode* getChild(int child) {
        return this->children[child];
    }
    
    void markEnd() {
        this->end = true;
    }
    
    bool isEnd() {
        return this->end;
    }
};

class WordDictionary {
private:
    TNode* root;
public:
    /** Initialize your data structure here. */
    WordDictionary() {
        root = new TNode();
    }
    
    /** Adds a word into the data structure. */
    void addWord(string word) {
        TNode* curr = root, *child;
        for (char x : word) {
            child = curr->getChild(x-'a');
            if (!child)
                curr->addChild(x-'a');
            curr = curr->getChild(x-'a');
        }
        curr->markEnd();
    }
    
    /** Returns if the word is in the data structure. A word could contain the dot character '.' to represent any one letter. */
    bool search(string word) {
        TNode* curr = root;
        return helper(0, curr, word);
    }
    
    bool helper(int currLetter, TNode* curr, string word) {
        int i;
        bool result;
        TNode* child;
        if (currLetter == word.length())
            return curr->isEnd();
        if (word[currLetter] != '.') {
            child = curr->getChild(word[currLetter]-'a');
            if (!child)
                return false;
            return helper(currLetter+1, child, word);
        }
        for (i = 0; i < 26; i++) {
            child = curr->getChild(i);
            if (child && helper(currLetter+1, child, word))
                return true;
        }
        return false;
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
