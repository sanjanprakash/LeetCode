class Solution {
public:
    bool validTransform(string a, string b) {
        int i, miss = 0;
        for (i = 0; i < a.length(); i++) {
            if (a[i] != b[i])
                miss++;
            if (miss == 2)
                return false;
        }
        return miss == 1;
    }
    
    unordered_map<string,vector<string> > edges(vector<string> &words, string &start, string &end) {
        int i,j;
        int n = words.size();
        unordered_map<string,vector<string> > graph;
        for (i = 0; i < n; i++) {
            if (validTransform(start,words[i]))
                graph[start].push_back(words[i]);
        }
        for (i = 0; i < n-1; i++) {
            for (j = i+1; j < n; j++) {
                if (validTransform(words[i],words[j])) {
                    if (words[i] == end)
                        graph[words[j]].push_back(words[i]);
                    else if (words[j] == end)
                        graph[words[i]].push_back(words[j]);
                    else {
                        graph[words[j]].push_back(words[i]);
                        graph[words[i]].push_back(words[j]);
                    }
                }
            }
        }
        return graph;
    }
    
    void backtrack(string &curr, string &start, unordered_map<string,vector<pair<string,int> > > &preds, vector<string> &uno, vector<vector<string> > &all) {
        if (curr == start) {
            uno.push_back(curr);
            all.push_back(uno);
            uno.pop_back();
            return;
        }
        uno.push_back(curr);
        for (auto x : preds[curr])
            backtrack(x.first,start,preds,uno,all);
        uno.pop_back();
    }
    
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        pair<string,int> pred;
        vector<string> uno;
        vector<vector<string> > ans, res;
        unordered_map<string,vector<pair<string,int> > > preds;
        unordered_map<string,vector<string> > graph;
        queue<pair<string,int> > Q;
        
        auto it_begin = find(wordList.begin(), wordList.end(), beginWord);
        if (it_begin != wordList.end())
            wordList.erase(it_begin);
        auto it_end = find(wordList.begin(), wordList.end(), endWord);
        if (it_end == wordList.end())
            return ans;
        
        graph = edges(wordList,beginWord,endWord);
        
        Q.push(make_pair(beginWord,1));
        while (!Q.empty()) {
            pred = Q.front();
            Q.pop();
            if (pred.first == endWord)
                break;
            for (auto succ : graph[pred.first]) {
                if (!preds[succ].size()) {
                    preds[succ].push_back(make_pair(pred.first,pred.second));
                    Q.push(make_pair(succ,pred.second+1));
                }
                else {
                    if (preds[succ][0].second == pred.second)
                       preds[succ].push_back(make_pair(pred.first,pred.second));
                }
            }
        }  
        
        backtrack(endWord,beginWord,preds,uno,res);
        for (auto x : res) {
            reverse(x.begin(),x.end());
            ans.push_back(x);
        }
        return ans;
    }
};
