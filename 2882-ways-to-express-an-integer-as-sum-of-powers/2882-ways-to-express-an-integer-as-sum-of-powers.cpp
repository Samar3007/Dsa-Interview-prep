class Solution {
public:
    int mod=1e9+7;
    int solve(int i, int x, int n, int sum, vector<vector<int>>& dp){
        if(n==sum) return 1;
        if(pow(i,x)>n-sum) return 0;
        if(dp[sum][i]!=-1) return dp[sum][i];
        int take=solve(i+1,x,n,sum+pow(i,x),dp);
        int notTake=solve(i+1,x,n,sum,dp);
        return dp[sum][i]=(take+notTake)%mod;
    }

    int numberOfWays(int n, int x) {

        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return solve(1, x, n, 0,dp);
    }
};