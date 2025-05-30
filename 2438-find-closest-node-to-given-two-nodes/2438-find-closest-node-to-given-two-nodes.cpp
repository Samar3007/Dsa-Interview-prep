class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<int> vis1(n), vis2(n), dis1(n,1e9), dis2(n,1e9);

        int ele=node1;
        dis1[node1]=0;
        dis2[node2]=0; 
        int dis=0;
        while(edges[ele]!=-1 && !vis1[edges[ele]]){
            vis1[ele]=1;
            dis++;
            dis1[edges[ele]]=min(dis1[edges[ele]],dis);
            ele=edges[ele];
        }
        
        dis=0;
        ele=node2;
        while(edges[ele]!=-1 && !vis2[edges[ele]]){
            vis2[ele]=1;
            dis++;
            dis2[edges[ele]]=min(dis2[edges[ele]],dis);
            ele=edges[ele];
        }

        int mini=1e8, ans=-1;
        for(int i=0;i<n;i++){
            if(mini > max(dis1[i],dis2[i])){
                mini=max(dis1[i],dis2[i]);
                ans=i;
            }
        }
        return ans;
    }
};