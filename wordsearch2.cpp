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

class Solution {
private:
    TNode *root;
public:
    Solution() {
        root = new TNode();
    }
    
    void DFS(TNode *root, vector<vector<char>>& board, vector<vector<bool>>& visited, string &s, vector<string> &ans, int i, int j) {
        int r = board.size(), c = board[0].size();
        int id = board[i][j]-'a';
        s.push_back(board[i][j]);
        visited[i][j] = true;
        if (root->kids[id]) {
            if (root->kids[id]->isEnd) 
                ans.push_back(s);
            if (i+1 < r && !visited[i+1][j])
                DFS(root->kids[id],board,visited,s,ans,i+1,j);
            if (j+1 < c && !visited[i][j+1])
                DFS(root->kids[id],board,visited,s,ans,i,j+1);
            if (i-1 > -1 && !visited[i-1][j])
                DFS(root->kids[id],board,visited,s,ans,i-1,j);
            if (j-1 > -1 && !visited[i][j-1])
                DFS(root->kids[id],board,visited,s,ans,i,j-1);
        }
        visited[i][j] = false;
        s.pop_back();
    } 
    
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        int i,j;
        int r = board.size(), c; 
        vector<string> res,ans;
        set<string> req_words;
        if (r && words.size()) {
            c = board[0].size();
            for (auto &x : words)
                root->insert(x);
            for (i = 0; i < r; i++) {
                for (j = 0; j < c; j++) {
                    string str = "";
                    vector<vector<bool> > visited(r,vector<bool>(c,false));
                    DFS(root,board,visited,str,res,i,j);
                }
            }
            for (auto &x : res)
                req_words.insert(x);
            for (auto &x : req_words)
                ans.push_back(x);
            sort(ans.begin(),ans.end());
        }
        return ans;
    }
};
