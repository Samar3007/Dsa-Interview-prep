//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n=grid.size();
        DisjointSet ds(n*n);
        int dx[4]={0,-1,0,1};
        int dy[4]={-1,0,1,0};
        
        //step-1 making components with different ultimate parents; 
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                for(int k=0;k<4;k++){
                    int row=i+dx[k];
                    int col=j+dy[k];
                    if(row<0 || row>=n || col<0 || col>=n) continue;
                    
                    if(grid[row][col]==1){
                        int node=i*n+j;
                        int adjNode=row*n+col;
                        if(ds.findUPar(node)!=ds.findUPar(adjNode)){
                            ds.unionBySize(node,adjNode);
                        }
                    }
                }
            }
            
        }
        
        int maxi=0;
        //step-2 connecting components
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1) continue;
                set<int> comp;
                for(int k=0;k<4;k++){
                    int row=i+dx[k];
                    int col=j+dy[k];
                    if(row<0 || row>=n || col<0 || col>=n) continue;
                    
                    if(grid[row][col]==1){
                        int newNode=row*n+col;
                        comp.insert(ds.findUPar(newNode));
                    }
                }
                int totSize=0;
                for(int it:comp){
                    totSize+=ds.size[it];
                }
                maxi=max(maxi,totSize+1);
            }
            
        }
        
        //for(int cell=0;cell<n*n;cell++){
            maxi=max(maxi,ds.size[ds.findUPar(0)]);
        //}
        return maxi;
        
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> grid(n, vector<int>(n));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> grid[i][j];
            }
        }

        Solution obj;
        cout<<obj.MaxConnection(grid)<<"\n";
    }
}

// } Driver Code Ends