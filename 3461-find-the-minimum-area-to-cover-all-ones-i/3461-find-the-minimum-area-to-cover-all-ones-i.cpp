class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        int miniRow=n+1, miniCol=m+1, maxiRow=-1, maxiCol=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    miniRow=min(miniRow,i);
                    miniCol=min(miniCol,j);
                    maxiRow=max(maxiRow,i);
                    maxiCol=max(maxiCol,j);
                }
            }
        }

        return (maxiRow-miniRow+1)*(maxiCol-miniCol+1);
    }
};