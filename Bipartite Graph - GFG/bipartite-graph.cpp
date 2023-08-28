//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    bool bfs(int start, vector<int>& color, vector<int>adj[]){
        queue<int> q;
    	color[start]=1;
    	q.push(start);
    
    	while(!q.empty()){
    		int node=q.front();
    		int col=color[node];
    		q.pop();
    
    		for(int x:adj[node]){
    			if(color[x]==0){
    			    color[x] = -col;
    			    q.push(x);
    			}
    			else if(color[x]==col) return false;
    			
            }
        }
    	return true;    // Code here
    }
	
	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V,0);
	    
	    for(int i=0;i<V;i++){
	        for(int x:adj[i]){
	            if(color[x]==0){
	                bool ans=bfs(x,color,adj);
	                if(!ans) return false;
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