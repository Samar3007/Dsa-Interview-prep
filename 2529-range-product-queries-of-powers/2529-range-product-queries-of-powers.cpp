class Solution {
public:
    int mod=1e9+7;
    // vector<int> genArr(int i, int n, int sum){
    //     vector<int> temp;
        
    //     while(sum != n){
    //         int num=1<<i;
    //         if(num <= n-sum){
    //             sum+=num;
    //             temp.push_back(num);
    //         }
    //         i--;
    //     }
    //     return temp;
    // }

    vector<int> givePowers(int n, int i){
        // while(1<<i <= n){
        //     i++;
        // }
        // vector<int> res = genArr(i-1,n,0);
        // sort(res.begin(),res.end());
        // return res;

        vector<int> arr;
        while(1<<i <= n){
            if(1<<i & n) arr.push_back(1<<i);
            i++;
        }
        
        return arr;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> powers=givePowers(n,0);
        int len=powers.size();
        
        // vector<long> prefProd(len+1,1);
        // for(int i=0;i<len;i++){
        //     prefProd[i+1]=(prefProd[i]*powers[i]) % mod;
        //     cout<<powers[i]<<' ';

        // }

        vector<int> res;
        for(auto &query : queries){
            int st=query[0], end=query[1];
            long ans=1;
            for(int i=st;i<=end;i++){
                ans=(ans*powers[i])%mod;
            }
            res.push_back(ans);
        }

        return res;
    }
};