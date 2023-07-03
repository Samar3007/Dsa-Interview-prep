class Solution {
public:
    
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n=maze.size();
        int m=maze[0].size();
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};

        vis[entrance[0]][entrance[1]]=true;
        queue<pair<int,int>> q;
        q.push({entrance[0],entrance[1]});
        
        int level=0;
        
        while(!q.empty()){
            int size=q.size();
            level++;
            while(size--){
                int Row=q.front().first;
                int Col=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nrow=Row+dx[i];
                    int ncol=Col+dy[i];
                    if(nrow>=0 && ncol>= 0 && nrow<n && ncol<m && !vis[nrow][ncol] && maze[nrow][ncol]=='.'){
                        vis[nrow][ncol]=true;
                        q.push({nrow,ncol});
                        if(nrow==0 || ncol == 0 || nrow==n-1 || ncol==m-1){
                            return level;
                        }
                    }
                }                        
            }
        }
            
           
        
        return -1;

    }
};