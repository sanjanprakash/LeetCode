class MovingAverage {
private:
    int *arr;
    int max_size;
    double sum, n;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        max_size = size;
        arr = new int[max_size];
        sum = 0.0;
        n = 0.0;
    }
    
    double next(int val) {
        if (int(n) < max_size) {
            arr[int(n)] = val;
            sum += double(val);
            n += 1.0;
            return sum/n;
        }
        else {
            sum -= double(arr[int(n)%max_size]);
            arr[int(n)%max_size] = val;
            sum += double(arr[int(n)%max_size]);
            n += 1.0;
            return sum/double(max_size);
        }
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
