class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>> &mat) {
        int n=mat.size(), m=mat[0].size(); 
        int dp[n][m];
        
        vector<int> prev(m,0);
        
        for(int row=0;row<n;row++){
            vector<int> temp(m,0);
            
            for(int col=0;col<m;col++){
            
                if(mat[row][col]==1) temp[col]=0;
                else if(row==0 && col==0) temp[col]=1;
                else{
                    int l=0,r=0;
                    if(row>0) l=prev[col];
                    if(col>0) r=temp[col-1];
                    temp[col]=(l+r);
                }
            }
            prev=temp;
            
        }
        return prev[m-1];
    }
};