class Solution {
private:
    int id = 0;
    bool first = true;
    vector<int> digits;
    unordered_map<string,string> l2s, s2l;
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        int i, num;
        string ans = "";
        if (l2s.find(longUrl) != l2s.end())
            return l2s[longUrl];
        if (first) {
            for (i = '0'; i <= '9'; i++)
                digits.push_back(i);
            for (i = 'a'; i <= 'z'; i++)
                digits.push_back(i);
            for (i = 'A'; i <= 'Z'; i++)
                digits.push_back(i);
            first = false;
        }
        id++;
        num = id;
        while (num) {
            ans += char(digits[num%62]);
            num /= 62;
        }
        l2s[longUrl] = ans;
        s2l[ans] = longUrl;
        return ans;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return s2l[shortUrl];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
