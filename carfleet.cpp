class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int i,n = speed.size();
        if (n < 2)
            return n;
        unordered_map<int,float>X;
        float temp;
        vector<int>dist;
        for (i = 0; i < n; i++) {
            X[position[i]] = float(target - position[i])/float(speed[i]);
            dist.push_back(position[i]);
        }
        sort(position.begin(),position.end(),greater<int>());
        temp = X[position[0]];
        for (i = 1; i < speed.size(); i++) {
            if (X[position[i]] <= temp)
                n--;
            else
                temp = X[position[i]];
        }
        return n;
    }
};
