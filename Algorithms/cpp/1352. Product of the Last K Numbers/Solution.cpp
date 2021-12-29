// https://leetcode.com/problems/product-of-the-last-k-numbers/

class ProductOfNumbers {
private:
    vector<int> products;
public:
    ProductOfNumbers() {
        //
    }
    
    void add(int num) {
        if(num == 0) products.clear();
        else products.push_back((products.empty()?1:products.back())*num);
    }
    
    int getProduct(int k) {
        if(k > products.size()) return 0;
        else if(k == products.size()) return products.back();
        return products.back()/products[products.size()-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */