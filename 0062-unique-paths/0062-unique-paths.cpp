class Solution {
public:
    int func(int row, int col, vector<vector<int>>& dp) {
        if(row==0 && col==0){
            return 1;
        }
        else if(row<0 || col<0) return 0;

        if(dp[row][col]!=-1) return dp[row][col];
        int l=func(row-1,col,dp);
        int r=func(row,col-1,dp);
        return dp[row][col]=l+r;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return func(m-1,n-1,dp);
    }

};