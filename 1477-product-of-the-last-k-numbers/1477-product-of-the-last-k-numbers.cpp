class ProductOfNumbers {
public:
    vector<long> vec = {1};
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num!=0){
            vec.push_back(vec.back()*num);
        }
        else{
            vec = {1};
        }
    }
    
    int getProduct(int k) {
        if(k<vec.size()) return vec.back()/vec[vec.size()-k-1];
        return 0;
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */