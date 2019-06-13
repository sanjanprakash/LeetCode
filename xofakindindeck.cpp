class Solution {
public:
    int gcd(int a, int b) {
        if (!b)
            return a;
        if (a > b)
            return gcd(b,a%b);
        return gcd(a,b%a);
    }
    
    bool hasGroupsSizeX(vector<int>& deck) {
        int i, hcf;
        map<int,int> freqs;
        map<int,int>::iterator it;
        if (deck.size() <= 1)
            return false;
        for (i = 0; i < deck.size(); i++)
            freqs[deck[i]]++;
        it = freqs.begin();
        hcf = gcd(it->second,it->second);
        it++;
        for (; it != freqs.end(); it++) {
            hcf = gcd(hcf,it->second);
            if (hcf == 1)
                return false;
        }
        return true;
    }
};
