class Solution {
public:
    void complexNumberFromString(string a, int &real_a, int &img_a) {
        int i = 0;
        bool real_neg = false, img_neg = false;
        if (a[i] == '-') {
            i++;
            real_neg = true;
        }
        while (a[i] != '+') {
            real_a *= 10;
            real_a += a[i] - '0';
            i++;
        }
        i++;
        if (a[i] == '-') {
            i++;
            img_neg = true;
        }
        while (a[i] != 'i') {
            img_a *= 10;
            img_a += a[i] - '0';
            i++;
        }
        if (real_neg)
            real_a *= -1;
        if (img_neg)
            img_a *= -1;
    }
    
    string complexNumberMultiply(string a, string b) {
        int a_r = 0,a_i = 0,b_r = 0,b_i = 0;
        int ans_r,ans_i;
        string ans = "";
        complexNumberFromString(a,a_r,a_i);
        complexNumberFromString(b,b_r,b_i);
        ans_r = a_r*b_r - a_i*b_i;
        ans_i = a_r*b_i + a_i*b_r;
        ans = to_string(ans_r) + "+" + to_string(ans_i) + "i";
        return ans;
    }
};
