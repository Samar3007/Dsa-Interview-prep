class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &mat) {
        int n=mat.size(), m=mat[0].size(); 
        int dp[n][m];
        
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(mat[row][col]==1) dp[row][col]=0;
                else if(row==0 && col==0) dp[row][col]=1;
                else{
                    int l=0,r=0;
                    if(row>0) l=dp[row-1][col];
                    if(col>0) r=dp[row][col-1];
                    dp[row][col]=(l+r);
                }
            }
        }
        return dp[n-1][m-1];
    }
};