class Solution {
public:
    vector<vector<int>> res;
    void func(int len, vector<int>& comb, int sum, int num){
        if(comb.size()>len || sum<0) return;
        if(comb.size()==len && sum==0){
            res.push_back(comb);
            return;
        }
        
        
    
        for(int i=num; i<=9; ++i) {
            comb.push_back(i);
            func(len, comb, sum-i,i+1);
            comb.pop_back();
        }
            
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> comb;
        func(k,comb,n,1);
        return res;
    }
};

