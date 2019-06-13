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
        int i, hcf = 0;
        map<int,int> freqs;
        map<int,int>::iterator it;
        if (deck.size() <= 1)
            return false;
        for (i = 0; i < deck.size(); i++)
            freqs[deck[i]]++;
        for (it = freqs.begin(); it != freqs.end(); it++) {
            hcf = gcd(it->second,hcf);
            if (hcf == 1)
                return false;
        }
        return true;
    }
};
