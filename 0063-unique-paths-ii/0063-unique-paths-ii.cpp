class Solution {
public:
    

    int func(int row, int col, vector< vector< int> > &mat, vector< vector< int> > &dp){
        if(row>=0 && col>=0 && mat[row][col]==1) return 0;
        if(row==0 && col==0) return 1;
        if(row<0 || col<0 ) return 0;
        if(dp[row][col]!=-1) return dp[row][col];
        int l=func(row-1,col,mat,dp);
        int r=func(row,col-1,mat,dp);
        return dp[row][col]=(l+r);

    }

    int uniquePathsWithObstacles(vector<vector<int>> &mat) {
        int n=mat.size(), m=mat[0].size(); 
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return func(n-1,m-1,mat,dp);
    }
};