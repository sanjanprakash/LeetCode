class Solution {
public:
    int clumsy(int N) {
        int num = N-1, temp;
        int op = 1, ans = 0;
        deque<int> S;
        S.push_back(N);
        while (op < N) {
            if (op%4 == 1) {
                temp = S.back();
                S.pop_back();
                S.push_back(temp*num);
            }
            else if (op%4 == 2) {
                temp = S.back();
                S.pop_back();
                S.push_back(temp/num);
            }
            else {
                S.push_back(num);
            }
            num--;
            op++;
        }
        op = 0;
        ans = S.front();
        S.pop_front();
        while (!S.empty()) {
            if (op%2)
                ans -= S.front();
            else
                ans += S.front();
            S.pop_front();
            op++;
        }
        return ans;
    }
};
