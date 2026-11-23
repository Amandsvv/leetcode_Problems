class ProductOfNumbers {
public:
    vector<int> pNums;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        int n = pNums.size();
        if(num == 0){
            pNums.clear();
        }else 
            if(n==0)
                pNums.push_back(num);
            else
                pNums.push_back(pNums[n-1] * num);
    }
    
    int getProduct(int k) {
        int n = pNums.size();
        if(k > n) return 0;
        if(n == k) return pNums[n-1];
        return pNums[n-1] / pNums[n-k-1];
    }
};



/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */