class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        queue<int>poppers;
        stack<int>pushers;
        int i,s;
        for (i = 0; i < popped.size(); i++)
            poppers.push(popped[i]);
        for (i = 0; i < pushed.size(); i++) {
            pushers.push(pushed[i]);
            s = min(pushers.size(),poppers.size());
            while (s != 0) {
                if (pushers.top() == poppers.front()) {
                    poppers.pop();
                    pushers.pop();
                    s--;
                }
                else
                    break;
            }
        }
        return pushers.empty();
}
};
