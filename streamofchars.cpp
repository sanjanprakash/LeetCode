class Trie {
private:
    bool isEnd;
    Trie *kids[26];
public:
    Trie() {
        int i;
        isEnd = false;
        for (i = 0; i < 26; i++)
            kids[i] = NULL;
    }
    
    void insert(Trie *root, string &s, int n) {
        int id;
        if (n) {
            id = s[n-1]-'a';
            if (!root->kids[id])
                root->kids[id] = new Trie();
            insert(root->kids[id],s,n-1);
        }
        else 
            root->isEnd = true;
    }
    
    bool walker(Trie *root, char *stream, int n) {
        int id;
        Trie *curr = root;
        while(n > -1) {
            id = stream[n]-'a';
            if (curr->kids[id])
                curr = curr->kids[id];
            else
                return false;
            if (curr->isEnd)
                return true;
            n--;
        }
        return false;
    }
};


class StreamChecker {
private:
    int curr;
    char stream[2000];
    Trie *root;
    
public:
    StreamChecker(vector<string>& words) {
        curr = 0;
        root = new Trie();
        for (auto &x : words)
            root->insert(root,x,x.length());
    }
    
    bool query(char letter) {
        bool ans;
        stream[curr] = letter;
        ans = root->walker(root,stream,curr);        
        curr = (curr+1) % 2000;
        return ans;
    }
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */
