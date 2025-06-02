class Solution {
public:
    int candy(vector<int>& r) {
        int n = r.size();
        vector<int> cnt (n,1);
        for(int i=1;i<n;i++){
            if(r[i]>r[i-1]) cnt[i]=cnt[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(r[i+1]<r[i]) cnt[i]=max(cnt[i],cnt[i+1]+1);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=cnt[i];
        }
        return ans;
    }
};