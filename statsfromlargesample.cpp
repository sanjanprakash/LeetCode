class Solution {
public:
    vector<double> sampleStats(vector<int>& count) {
        int i = 0, max = 0, max_id;
        long long int sum = 0, num = 0, c = 0, m1, m2;
        vector<double> ans;
        while (count[i] == 0)
            i++;
        ans.push_back(double(i));
        i = 255;        
        while (count[i] == 0)
            i--;
        ans.push_back(double(i));
        for (i = 0; i < 256; i++) {
            sum += i*count[i];
            num += count[i];
        }
        ans.push_back(double(sum)/double(num));
        if (num%2) {
            i = 0;
            while (i < 256 && c < num/2) {
                c += count[i];
                i++;
            }
            ans.push_back(double(i-1));
        }
        else {
            i = 0;
            while (i < 256 && c < num/2) {
                c += count[i];
                i++;
            }
            if (c > num/2)
                ans.push_back(double(i-1));
            else {
                m1 = i-1;
                while (count[i] == 0)
                    i++;
                ans.push_back(double(i+m1)/2);
            }
        }
        for (i = 0; i < 256; i++) {
            if (count[i] > max) {
                max = count[i];
                max_id = i;
            }
        }
        ans.push_back(double(max_id));
        return ans;        
    }
};
