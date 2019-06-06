class Solution {
public:
    struct desc_sort {
        bool operator()(const pair<int,int> &A, const pair<int,int> &B) {
            return A.second > B.second;
        }
    };
    
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        int i,j,k;
        vector<int> ans(barcodes.size(),0);
        vector<pair<int,int> > freqs;
        map<int,int> counter;
        map<int,int>::iterator it;
        for (i = 0; i < barcodes.size(); i++)
            counter[barcodes[i]]++;
        for (it = counter.begin(); it != counter.end(); it++)
            freqs.push_back(make_pair(it->first,it->second));
        sort(freqs.begin(),freqs.end(),desc_sort());
        i = 0;
        j = 0;
        for (k = 0; k < 2; k++) {
            while (i < barcodes.size()) {
                ans[i] = freqs[j].first;
                freqs[j].second--;
                if (!freqs[j].second)
                    j++;
                i += 2;
            }
            i = 1;
        }
        return ans;
    }
};
