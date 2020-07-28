class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int i, idles;
        vector<int> freqs(26, 0);
        for (char x : tasks)
            freqs[x-'A']++;
        sort(freqs.begin(), freqs.end());
        idles = (freqs[25]-1)*n;
        for (i = 24; i > -1; i--)
            idles -= min(freqs[25]-1, freqs[i]);
        idles = max(0, idles);
        return tasks.size() + idles;
    }
};
