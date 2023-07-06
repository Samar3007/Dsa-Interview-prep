class Solution {
public:
    int func(vector<vector<int>>& tri, int i, int j, int n, vector<vector<int>>& dp){
        if(i==n-1) return tri[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int d=tri[i][j] + func(tri,i+1,j,n,dp);
        int dg=tri[i][j] + func(tri,i+1,j+1,n,dp);
        return dp[i][j]=min(d,dg);
    }
    
    
    int minimumTotal(vector<vector<int>>& tri) {
        int n=tri.size();
        vector<vector<int>> dp(n,vector<int>(n,0));
        
        for(int j=0;j<n;j++){
            dp[n-1][j]=tri[n-1][j];
        }
        
        for(int i=n-2;i>=0;i--){
            for(int j=i;j>=0;j--){
                int d=tri[i][j] + dp[i+1][j];
                int dg=tri[i][j] + dp[i+1][j+1];
                dp[i][j]=min(d,dg);
            }
        }
	    return dp[0][0];
    }
};