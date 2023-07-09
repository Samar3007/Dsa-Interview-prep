class Solution {
public:
    void dfs(vector<vector<int>>& image, int sr, int sc, int val, int color){
        if(sr<0 || sr>=image.size() || sc<0 || sc>=image[0].size() || image[sr][sc]!=val || image[sr][sc]==color) return;
        image[sr][sc]=color;
        dfs(image,sr+1,sc,val,color);
        dfs(image,sr-1,sc,val,color);
        dfs(image,sr,sc+1,val,color);
        dfs(image,sr,sc-1,val,color);
    }
   
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val=image[sr][sc];
        dfs(image,sr,sc,val,color);
        return image;
    }
};
  /*    int n=image.size(), m=image[0].size();
        queue<pair<int,int>> q;
        image[sr][sc]=color;
        q.push({sr,sc});
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=row+dx[i];
                int ny=row+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    if(image[nx][ny]!=color && image[nx][ny]!=0){
                        image[nx][ny]=color;
                        q.push({nx,ny});
                    }
                }
            }
            
        }
        return image;
        
    }
    */
    
