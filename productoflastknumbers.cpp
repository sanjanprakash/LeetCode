class ProductOfNumbers {
private:
    int n;
    vector<int> products;
public:
    ProductOfNumbers() {
        n = 1;
        products.push_back(1);
    }
    
    void add(int num) {
        if (num == 0) {
            products.clear();
            products.push_back(1);
            n = 1;
        }
        else {
            products.push_back(products[n-1]*num);
            n++;
        }
    }
    
    int getProduct(int k) {
        if (k >= n)
            return 0;
        return products[n-1]/products[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
