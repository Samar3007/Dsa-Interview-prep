class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp, int n, int m){
        if(i>=n || j>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(matrix[i][j]==0) return 0;
        int right=solve(i,j+1,matrix,dp,n,m);
        int down=solve(i+1,j,matrix,dp,n,m);
        int diag=solve(i+1,j+1,matrix,dp,n,m);
        return dp[i][j]=1+min(down,min(right,diag));
    }
    
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        int result=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]) result+=solve(i,j,matrix,dp,n,m);
            }
        }
        return result;
    }
};