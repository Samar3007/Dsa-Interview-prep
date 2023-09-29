//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void bfs(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &vis){
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        q.push({i,j});
        grid[i][j]=2;
        vis[i][j]=1;
        
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int r=0;r<4;r++){
                int nRow=row+dx[r];
                int nCol=col+dy[r];
                if(nRow>=0 && nRow <n && nCol>=0 && nCol<m && !vis[nRow][nCol] && grid[nRow][nCol]){
                    grid[nRow][nCol]=2;
                    vis[nRow][nCol]=1;
                    q.push({nRow,nCol});
                    
                }
            }
        }
    }
    int numberOfEnclaves(vector<vector<int>> &grid) {
        // Code here
        int n=grid.size();
        int m=grid[0].size();
        int cnt=0;
        vector<vector<int>> vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j] && (i==0 || j==0 || i==n-1 || j==m-1)){
                    bfs(i,j,grid,vis);
                }
            }
        }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !vis[i][j]){
                    cnt++;
                }
            }
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        cout << obj.numberOfEnclaves(grid) << endl;
    }
}
// } Driver Code Ends