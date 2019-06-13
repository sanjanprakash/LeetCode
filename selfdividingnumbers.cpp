class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        int i, num, dig;
        bool flag;
        vector<int> ans;
        for (i = left; i < right+1; i++) {
            num = i;
            flag = true;
            while (flag && num > 0) {
                dig = num%10;
                if (!dig || i%dig != 0)
                    flag = false;
                num /= 10;
            }
            if (flag)
                ans.push_back(i);
        }
        return ans;
    }
};
