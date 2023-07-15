//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
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
        
        int lvl=0;
        int dx[4]={1,0,-1,0};
        int dy[4]={0,1,0,-1};
    
        while(!q.empty()){
            int size=q.size();
       
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
     
        return lvl;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends