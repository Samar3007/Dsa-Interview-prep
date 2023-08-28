//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool dfs(int node, vector<int>& color, int col, vector<int>adj[]){
        color[node]=col;
		
		for(int x:adj[node]){
			if(color[x]==0){
			    if(dfs(x,color,-col,adj)==false) return false;
			}
			else if(color[x]==col) return false;
			
        }
        
    	return true;    // Code here
    }
	
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V,0);
	    
	    for(int i=0;i<V;i++){
	        for(int x:adj[i]){
	            if(color[x]==0){
	                if(dfs(x,color,1,adj)==false) return false;
	            }
	        }
	    }
	    
	    return true;
    	
	}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}
// } Driver Code Ends