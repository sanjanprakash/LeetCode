struct Compare {
    bool operator() (string a, string b) {
        return a+b > b+a;
    } 
};

class Solution {
public:
    bool compare(const string &a, const string &b) {
        return a+b > b+a;
    }
    
    string largestNumber(vector<int>& nums) {
        string ans = "";
        vector<string> numbers;
        for (int x : nums)
            numbers.push_back(to_string(x));
        sort(numbers.begin(), numbers.end(), Compare());
        for (auto &x : numbers)
            ans += x;
        return ans[0] == '0' ? "0" : ans;
    }
};
