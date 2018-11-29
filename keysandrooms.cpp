class Solution {
public:
    void DFS(int s, vector<vector<int>>& rooms, bool* visited) {
        if (visited[s] == false) {
            int i;
            visited[s] = true;
            for (i = 0; i < rooms[s].size(); i++) {
                if (visited[rooms[s][i]] == false) 
                    DFS(rooms[s][i],rooms,visited);
            }
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        int i;
        bool *visited = new bool[n];
        for (i = 0; i < n; i++)
            visited[i] = false;
        DFS(0,rooms,visited);
        for (i = 0; i < n; i++) {
            if (visited[i] == false)
                return false;
        }
        return true;
    }
};
