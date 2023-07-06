class Solution {
public:
    int func(vector<vector<int>>& tri, int i, int j, int n, vector<vector<int>>& dp){
        if(i==n-1) return tri[i][j];
        if(dp[i][j]!=-1) return dp[i][j];
        int d=tri[i][j] + func(tri,i+1,j,n,dp);
        int dg=tri[i][j] + func(tri,i+1,j+1,n,dp);
        return dp[i][j]=min(d,dg);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
	    return func(triangle,0,0,n,dp);
    }
};