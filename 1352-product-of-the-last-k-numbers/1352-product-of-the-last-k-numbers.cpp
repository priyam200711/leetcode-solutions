class ProductOfNumbers {
public:
     vector<int>v;
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num==0)v.clear();
        else if(v.empty())v.push_back(num);
        else {
            int n=v.size();
            v.push_back(v[n-1]*num);
        }

    }
    
    int getProduct(int k) {
       int n=v.size();
       if(k>v.size())return 0;
       else if(k==n)return v[n-1];
       else return v[n-1]/v[n-k-1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */