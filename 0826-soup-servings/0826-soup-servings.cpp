class Solution {
public:
    double solve(int a, int b, vector<vector<double>> &dp){
        if(a<=0 && b<=0) return 0.5;
        else if(a<=0) return 1;
        else if(b<=0) return 0;
        if(dp[a][b]!=-1) return dp[a][b];

        double first = 0.25*solve(a-100,b,dp);
        double second = 0.25*solve(a-75,b-25,dp);
        double third = 0.25*solve(a-50,b-50,dp);
        double fourth = 0.25*solve(a-25,b-75,dp);
        return dp[a][b] = first+second+third+fourth;
    }
    
    double soupServings(int n) {
        if(n>=1e4) return 1;
        vector<vector<double>> dp(n+100,vector<double> (n+100,-1));
        return solve(n,n,dp);
    }
};