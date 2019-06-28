class Solution {
public:
    int maximumSwap(int num) {
        int i, j;
        int max_id;
        char temp;
        bool flag = false;
        string n = to_string(num);
        for (i = 0; i < n.length()-1; i++) {
            max_id = -1;
            for (j = i+1; j < n.length(); j++) {
                if (max_id == -1) {
                    if (n[i] < n[j])
                        max_id = j;
                }
                else {
                    if (n[j] >= n[max_id])
                        max_id = j;
                }
            }
            if (max_id != -1) {
                temp = n[max_id];
                n[max_id] = n[i];
                n[i] = temp;
                flag = true;
            }
            if (flag)
                break;
        }
        return stoi(n);
    }
};
