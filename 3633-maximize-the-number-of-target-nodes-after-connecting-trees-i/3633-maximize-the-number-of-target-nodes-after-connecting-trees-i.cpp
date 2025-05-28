class Solution {
public:

    int bfs(unordered_map<int,vector<int>>& adj, int d, int node, int N){
        vector<bool> visited(N, false);
        queue<pair<int,int>> q;
        
        q.push({0,node});
        visited[node] = true;
        int cnt = 0;
        
        while(!q.empty()){
            int currDist = q.front().first;
            int currNode = q.front().second;
            q.pop();
            if(currDist > d) continue;
            
            cnt++;
            for(int &it: adj[currNode]){
                if(!visited[it]){
                    q.push({currDist+1,it});
                    visited[it] = true;
                }
            }
        }
        return cnt;
    }

    vector<int> findTarget(vector<vector<int>>& edges, int d){
        unordered_map<int,vector<int>> adj;
        
        for(auto& edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int nodes = edges.size()+1;
        vector<int> freq(nodes);

        for(int i=0;i<nodes;i++){
            freq[i] = bfs(adj, d, i, nodes);
        }

        return freq;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        
        vector<int> freq1, freq2;
        freq1 = findTarget(edges1, k);
        freq2 = findTarget(edges2, k-1);

        int maxi = *max_element(freq2.begin(), freq2.end());

        for(int i=0;i<freq1.size();i++){
            freq1[i]+=maxi;
        }

        return freq1;
    }
};