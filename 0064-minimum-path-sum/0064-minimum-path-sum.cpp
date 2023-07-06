class Solution {
public:

    int minPathSum(vector<vector<int> > &matrix){
        int n=matrix.size(), m=matrix[0].size();
        vector<vector<int> > dp(n,vector<int>(m,-1));
        vector<int> prev(m,0);
        
        for(int i=0;i<n;i++){
            
            vector<int> curr(m,0);
            for(int j=0;j<m;j++){
                
                if(i==0 && j==0) curr[0]=matrix[0][0];
                
                else{
                    int left=1e9,up=1e9;
                    if(i>0) up = matrix[i][j] + prev[j];
                    if(j>0) left = matrix[i][j] + curr[j-1];
                    curr[j]=min(left,up);
                }
                
            }
            prev=curr;
        }

        return prev[m-1];

    }
};