class Solution {
public:
    int fun(int ind, vector<int>& cost, vector<int>& dp){
        if(ind<0) return 0;
        if (ind==0 || ind==1) return cost[ind];
        if(dp[ind]!= -1) return dp[ind];
        dp[ind]=cost[ind]+min(fun(ind-1, cost, dp),fun(ind-2,cost, dp));
        return dp[ind];
    }
        
    
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int> dp(n,-1);
        return min(fun(n-1,cost, dp),fun(n-2, cost, dp));
    }
    
};

