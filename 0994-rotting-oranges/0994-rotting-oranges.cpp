class Solution {
public:
    int dx[4]={1,0,-1,0};
    int dy[4]={0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size(), m=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
       
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                }
            }
        }
        
        int count=0;
        
        int lvl=0;
        
        
        while(!q.empty()){
            int size=q.size();
            count++;
            for(int i=0;i<size;i++){
                int nRow=q.front().first.first;
                int nCol=q.front().first.second;
                int mint=q.front().second;
                q.pop();
                for(int j=0;j<4;j++){
                    int x=nRow+dx[j];
                    int y=nCol+dy[j];
                    if(x>=0 && x<n && y>=0 && y<m){
                        if(grid[x][y]==1){
                            q.push({{x,y},mint+1});
                            grid[x][y]=2;
                        }
                    }
                }
                 lvl=mint;
                
            }
           
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    return -1;
                }
            }
        }
        if(count==1) return 0;
        return lvl;
    }
};