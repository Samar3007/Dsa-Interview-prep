class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> dir{{0,1},{0,-1},{-1,0},{1,0}};
    
    int minTimeToReach(vector<vector<int>>& mT) {
        
        int n=mT.size(), m=mT[0].size();
        vector<vector<int>> res(n,vector<int>(m,INT_MAX));
        res[0][0]=0;
        
        priority_queue<P,vector<P>,greater<P>> pq;
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            int curr_time=pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            if(i==n-1 && j==m-1){
                return curr_time;
            }
            for(auto it:dir){
                int i_=i+it[0];
                int j_=j+it[1];
                if(i_>=0 && i_<n && j_>=0 && j_<m){
                    int move=(i_+j_)%2==0 ? 2 : 1;
                    int arrTime=max(mT[i_][j_],curr_time)+move;
                    if(res[i_][j_]>arrTime){
                        res[i_][j_]=arrTime;
                        pq.push({arrTime,{i_,j_}});
                    }
                }
            }
        }
        return -1;
    }
};