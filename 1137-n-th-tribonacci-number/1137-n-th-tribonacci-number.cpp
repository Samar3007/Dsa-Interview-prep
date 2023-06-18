class Solution {
public:
    int func(int ind,vector<int>& dp){
        if(ind==0) return 0;
        if(ind==2 || ind==1) return 1;
       
        if(dp[ind]!=-1) return dp[ind];
        return dp[ind]=func(ind-1,dp) + func(ind-2,dp) + func(ind-3,dp);
    }
    
    int tribonacci(int n) {
        vector<int> dp( n+1,-1);
        return func(n,dp);
    }
};