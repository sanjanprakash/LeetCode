class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int i = 0, n = arr.size();
        bool first = false;
        queue<int> Q;
        while (i < n) {
            if (!first) {
                if (arr[i] == 0) {
                    first = true;
                    if (i+1 < n) {
                        Q.push(arr[i+1]);
                        arr[i+1] = 0;
                        i++;
                    }
                }
            }
            else {
                Q.push(arr[i]);
                arr[i] = Q.front();
                Q.pop();
                if (arr[i] == 0 && i+1 < n) {
                    Q.push(arr[i+1]);
                    arr[i+1] = 0;
                    i++;
                }
            }
            i++;
        }
    }
};
