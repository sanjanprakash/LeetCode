class Solution {
public:
    int highestProperFactor(int n) {
        int i;
        vector<int>factors;
        for (i = 2; i <= int(sqrt(n)); i++) {
            if (n % i == 0)
                factors.push_back(i);
        }
        return factors.size() > 0 ? n/factors[0] : n;
    }
    int minSteps(int n) {
        int *arr = new int[n+1];
        int i;
        int highestFactor;
        arr[0] = 0;
        arr[1] = 0;
        arr[2] = 2;
        for (i = 3; i <= n; i++) {
            highestFactor = highestProperFactor(i);
            if (highestFactor == i)
                arr[i] = i;
            else 
                arr[i] = arr[highestFactor] + (i/highestFactor);
        }
        return arr[n];   
    }
};
