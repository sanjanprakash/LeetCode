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
        return true;
    }
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int i;
        pair<string,int> curr;
        queue<pair<string,int> > Q;
        Q.push(make_pair(beginWord,1));
        
        auto it = std::find(wordList.begin(), wordList.end(), beginWord);
        if (it != wordList.end())
            wordList.erase(it);

        while (!Q.empty()) {
            curr = Q.front();
            Q.pop();
            if (curr.first == endWord)
                return curr.second;
            for (i = 0; i < wordList.size(); i++) {
                if (validTransform(curr.first,wordList[i])) {
                    Q.push(make_pair(wordList[i],curr.second+1));
                    wordList.erase(wordList.begin()+i);
                    i--;
                }
            }
        }
        return curr.first == endWord ? curr.second : 0;
    }
};
