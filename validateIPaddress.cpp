class Solution {
public:
    bool isValidIPv4Char(string& group) {
        int n = group.length(), count = 0;
        int num;
        if (n > 1 && group[0] == '0')
            return false;
        if (n > 3)
            return false;
        for (auto &x : group) {
            if (x-'0' < 0 || x-'0' > 9)
                return false;
        }
        num = stoi(group);
        return num >= 0 && num <= 255;
    }
    
    bool isValidIPv6Char(string& group) {
        int n = group.length(), count = 0;
        for (auto &x : group) {
            if (!isdigit(x) && !isalpha(x))
                return false;
            if (islower(x) && (x-'a' > 5))
                return false;
            if (isupper(x) && (x-'A' > 5))
                return false;
        }
        return true;
    }
    
    bool isIPv4(vector<string>& groups) {
        int num;
        for (auto &x : groups) {
            if (!isValidIPv4Char(x))
                return false;
        }
        return true;
    }
    
    bool isIPv6(vector<string>& groups) {
        int num;
        for (auto &x : groups) {
            if (x.length() > 4)
                return false;
            if (!isValidIPv6Char(x))
                return false;
        }
        return true;
    }
    
    bool checkIPv4(string& IP, vector<string>& groups) {
        int i, n = IP.length();
        int prev = -1;
        for (i = 0; i < n; i++) {
            if (IP[i] == '.') {
                groups.push_back(IP.substr(prev+1, i-prev-1));
                prev = i;
            }
        }
        groups.push_back(IP.substr(prev+1, i-prev-1));
        for (auto &x : groups) {
            if (!x.size())
                return false;
        }
        return groups.size() == 4;
    }
    
    bool checkIPv6(string& IP, vector<string>& groups) {
        int i, n = IP.length();
        int prev = -1;
        groups.clear();
        for (i = 0; i < n; i++) {
            if (IP[i] == ':') {
                groups.push_back(IP.substr(prev+1, i-prev-1));
                prev = i;
            }
        }
        groups.push_back(IP.substr(prev+1, i-prev-1));
        for (auto &x : groups) {
            if (!x.size())
                return false;
        }
        return groups.size() == 8;
    } 
    
    string validIPAddress(string IP) {
        int i, n = IP.length();
        int prev = -1;
        string ans = "Neither";
        bool IPv4 = false, IPv6 = false;
        vector<string> groups;
        IPv4 = checkIPv4(IP, groups);
        if (!IPv4)
            IPv6 = checkIPv6(IP, groups);
        
        if (IPv4 && isIPv4(groups))
            ans = "IPv4";
        else if (IPv6 && isIPv6(groups))
            ans = "IPv6";
        return ans;
    }
};
