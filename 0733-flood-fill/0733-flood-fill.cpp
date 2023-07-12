class Solution {
public:
    int dx[4]={0,1,0,-1};
    int dy[4]={1,0,-1,0};

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val=image[sr][sc];
        
        int n=image.size();
        int m=image[0].size();
        queue<pair<int,int>> q;
        image[sr][sc]=color;
        q.push({sr,sc});
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nx=row+dx[i];
                int ny=col+dy[i];
                if(nx>=0 && nx<n && ny>=0 && ny<m){
                    if(image[nx][ny]!=color && image[nx][ny]==val){
                        image[nx][ny]=color;
                        q.push({nx,ny});
                    }
                }
            }
            
        }
        return image;
        
    }
};
    
