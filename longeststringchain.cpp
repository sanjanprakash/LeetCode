class Solution {
private:
    unordered_map<string,vector<string> > graph;
    unordered_map<string,bool> visited, grey;
public:
    bool valid(string& a, string& b) {
        int i = 0, j = 0;
        if (abs(int(a.length()-b.length())) != 1)
            return false;
        while(i < a.length() && j < b.length() && a[i] == b[j]) {
            i++;
            j++;
        }
        if (i == a.length() || j == b.length())
            return true;
        if (a.length() > b.length())
            i++;
        else
            j++;
        while(i < a.length() && j < b.length() && a[i] == b[j]) {
            i++;
            j++;
        }
        return i == a.length() && j == b.length();
    }
    
    int DFS(string& start, int len, int& best) {
        int curr;
        if (!graph[start].size()) {
            return len;
        }
        else {
            visited[start] = true;
            grey[start] = true;
            for (auto &x : graph[start]) {
                curr = DFS(x,len+1,best);
                best = max(curr,best);
            }
            grey[start] = false;
            return best;
        }
    }
    
    int longestStrChain(vector<string>& words) {
        int i,j;
        int ans = INT_MIN;
        for (i = 0; i < words.size()-1; i++) {
            for (j = i+1; j < words.size(); j++) {
                if (valid(words[i],words[j])) {
                    if (words[i].length() > words[j].length()) {
                        graph[words[j]].push_back(words[i]);
                    }
                    else {
                        graph[words[i]].push_back(words[j]);
                    }
                }
            }
        }
        for (i = 0; i < words.size(); i++) {
            ans = max(ans,DFS(words[i],1,ans));
            for (j = 0; j < words.size(); j++) {
                grey[words[j]] = false;
                visited[words[j]] = false;
            }
        }
        return ans;
    }
};
