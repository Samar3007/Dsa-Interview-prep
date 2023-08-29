//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<vector<int>> adj(N);
        
        for(int i=0;i<M;i++){
            int u=edges[i][0], v=edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        queue<pair<int,int>> q;
        q.push({src,0});
        vector<int> dis(N,1e9);
        dis[src]=0;
        
        while(!q.empty()){
            int node=q.front().first;
            int level=q.front().second;
            q.pop();
            
            for(int x:adj[node]){
                if(dis[x]>level+1){
                    dis[x]=level+1;
                    q.push({x,dis[x]});
                }
                
            }
        }
        for(int i=0;i<dis.size();i++){
            if(dis[i]==1e9) dis[i]=-1;
        }
        return dis;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends