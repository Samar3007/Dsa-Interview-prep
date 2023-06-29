class Solution {
public:
    int mod=1000000007;

    int numTilings(int n) {
        vector<int> v(1001,0);
        v[1]=1;
        v[2]=2;
        v[3]=5;
        if(n<=3) return v[n];
        for(int i=4;i<=n;i++){
            v[i]=(2*v[i-1]%mod+v[i-3]%mod)%mod;
        }
        return v[n];
    }
};