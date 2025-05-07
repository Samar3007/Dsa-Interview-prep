class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> pos{{0,1},{1,0},{0,-1},{-1,0}};
    int minTimeToReach(vector<vector<int>>& mT) {
        int n = mT.size(), m = mT[0].size();
        
        priority_queue<P, vector<P>, greater<P>> pq;
        vector<vector<int>> res (n,vector<int>(m,INT_MAX));

        res[0][0]=0;
        pq.push({0,{0,0}});
        
        while(!pq.empty()){
            int curr_time = pq.top().first;
            auto dim = pq.top().second;
            int i = dim.first;
            int j = dim.second;
            if(i == n-1 && j == m-1) return curr_time;
            pq.pop();

            for(auto it:pos){
                int i_new = i+it[0];
                int j_new = j+it[1];
                
                if(i_new >=0 && i_new<n && j_new>=0 && j_new<m){
                    int arrTime = max(curr_time , mT[i_new][j_new]) + 1;

                    if(res[i_new][j_new] > arrTime){
                        res[i_new][j_new] = arrTime;
                        pq.push({arrTime , {i_new , j_new}});
                    }
                }
            }
        }
        return -1;
    }
};