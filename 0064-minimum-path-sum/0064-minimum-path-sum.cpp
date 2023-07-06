class Solution {
public:

    int minPathSum(vector<vector<int> > &matrix){
        int n=matrix.size(), m=matrix[0].size();
        vector<vector<int> > dp(n,vector<int>(m,-1));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(i==0 && j==0) dp[0][0]=matrix[0][0];
                
                else{
                    int left=1e9,up=1e9;
                    if(i>0) up = matrix[i][j] + dp[i-1][j];
                    if(j>0) left = matrix[i][j] + dp[i][j-1];
                    dp[i][j]=min(left,up);
                }
                
            }
        }

        return dp[n-1][m-1];

    }
};