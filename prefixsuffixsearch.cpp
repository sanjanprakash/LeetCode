class TNode {
public:
    int weight;
    bool isEnd;
    vector<int> weights;
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
    
    void insert(string &key, int w) {
        int id;
        TNode *move = this;
        for (auto &x : key) {
            id = x-'a';
            move->weights.push_back(w);
            if (!move->kids[id])
                getNode(move,id);
            move = move->kids[id];
        }
        move->isEnd = true;
        move->weights.push_back(w);
    }
};

class WordFilter {
private:
    TNode *forward, *backward;
    vector<string> lis;
public:
    WordFilter(vector<string>& words) {
        int i, n = words.size();
        lis = words;
        forward = new TNode();
        backward = new TNode();
        for (i = 0; i < n; i++) {
            forward->insert(words[i],i);
            reverse(words[i].begin(),words[i].end());
            backward->insert(words[i],i);
            reverse(words[i].begin(),words[i].end());
        }
    }
    
    int f(string prefix, string suffix) {
        int i,j;
        int id;
        int pre, suf;
        TNode *f = forward, *r = backward;
        for (auto &x : prefix) {
            id = x-'a';
            if (!f->kids[id])
                return -1;
            f = f->kids[id];
        }
        reverse(suffix.begin(),suffix.end());
        for (auto &x : suffix) {
            id = x-'a';
            if (!r->kids[id])
                return -1;
            r = r->kids[id];
        }
        i = f->weights.size()-1;
        j = r->weights.size()-1;
        while (i > -1 && j > -1) {
            if (f->weights[i] == r->weights[j])
                return f->weights[i];
            else if (f->weights[i] < r->weights[j])
                j--;
            else
                i--;
        }
        return -1;
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
