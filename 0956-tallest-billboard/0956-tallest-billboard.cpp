class Solution {
public:
    int offset=5000;
    int dp[20][10001];
    
    int func(int ind, int diff, vector<int>& rods){
        if(ind==rods.size()){
            if(diff==0)
                return 0;
            return -5000;
        }
        
        if(dp[ind][offset+diff]!=-1){
            return dp[ind][offset+diff];
        }
        
        int ans1=func(ind+1,diff,rods);
        int ans2=rods[ind]+func(ind+1,diff+rods[ind],rods);
        int ans3=rods[ind]+func(ind+1,diff-rods[ind],rods);
        
        return dp[ind][offset+diff]=max(ans1,max(ans2,ans3));
    }
    
    int tallestBillboard(vector<int>& rods) {
        memset(dp,-1,sizeof(dp));
        int ans=func(0,0,rods)/2;
        
        if(ans<0){
            ans=0;
        }
        return ans;
    }
};