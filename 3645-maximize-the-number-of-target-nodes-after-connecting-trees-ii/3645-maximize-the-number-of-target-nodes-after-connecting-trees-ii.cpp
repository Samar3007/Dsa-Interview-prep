class Solution {
public:

    vector<int> bfs(vector<vector<int>>& edges, int n){
        unordered_map<int,vector<int>> adj;
        
        for(auto& edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> mark(n);
        queue<pair<int,int>> q;
        vector<bool> vis(n,false);

        q.push({0,0});
        vis[0]=true;
        mark[0]=0;
        while(!q.empty()){
            int alt = q.front().first;
            int node = q.front().second;
            q.pop();
            for(auto it: adj[node]){
                if(!vis[it]){
                    vis[it]=true;
                    q.push({!alt,it});
                    mark[it]=!alt;
                }
            }
        }
        return mark;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        vector<int> mark1, mark2;
        int n1 = edges1.size()+1, n2 = edges2.size()+1;
        mark1 = bfs(edges1, n1);
        mark2 = bfs(edges2, n2);
        
        vector<int> ans(n1);
        int maxi = 0, cnt0=0, cnt1=0;
        for(int i=0;i<n2;i++){
            if(mark2[i]==0) cnt0++;
            else cnt1++;
        }
        maxi=max(cnt0,cnt1);

        int zeros = 0, ones = 0;
        for(int it:mark1){
            if(it==0) zeros++;
            else ones++;
        }
        
        for(int i=0;i<n1;i++){
            if(mark1[i]==1) ans[i]=ones+maxi;
            else ans[i]=zeros+maxi;
        }
        return ans;
    }
};