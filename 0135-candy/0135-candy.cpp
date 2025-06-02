class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        vector<int> l2r (n,1), r2l (n,1);
        for(int i=1;i<n;i++){
            if(r[i]>r[i-1]) l2r[i]=l2r[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(r[i+1]<r[i]) r2l[i]=r2l[i+1]+1;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=max(l2r[i],r2l[i]);
        }
        return ans;
    }
};