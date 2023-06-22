class Solution {
public:
 
    int dp[50002][2];
    
    int solve(int ind, int buy, vector<int>& prices, int fee){
        int maxPt=INT_MIN;
        
        if(ind>=prices.size()) return 0;
        
        if(dp[ind][buy]!=-1) return dp[ind][buy];
        if(buy==1){
            maxPt=max(-prices[ind] + solve(ind+1, 0, prices, fee), solve(ind+1, 1, prices,fee));
        }
        else{
            maxPt=max(+prices[ind] + solve(ind+1, 1, prices, fee) - fee, solve(ind+1, 0, prices,fee));
        }
        
        return dp[ind][buy]=maxPt;
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(dp,-1,sizeof(dp));
        return solve(0,1,prices,fee);
    }
};