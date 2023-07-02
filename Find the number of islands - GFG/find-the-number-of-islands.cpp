//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:

    void bfs(vector<vector<int>>& vis, int row, int col, vector<vector<char>>& grid){
        queue<pair<int,int>> q;
        vis[row][col]=1;
        int n=grid.size(), m=grid[0].size();
    
        q.push({row,col});
        while(!q.empty()){
            
            int Row=q.front().first;
            int Col=q.front().second;
            q.pop();
            
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nrow=Row+i;
                    int ncol=Col+j;
                    if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]=='1' && !vis[nrow][ncol]){
                        vis[nrow][ncol]=1;
                        q.push({nrow,ncol});
                    }
                }
            }
        }
        return;
    }
    
    // Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) {
        int cnt=0;
        int n=grid.size(), m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(vis,i,j,grid);
                }
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends