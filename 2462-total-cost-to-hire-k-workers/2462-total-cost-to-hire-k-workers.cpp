class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        long long ans=0;
        long long n=costs.size();
        
        priority_queue<int,vector<int>,greater<int>> q1,q2;
    
        int l=0, r=n-1;
        int cnt=0;
        while(cnt<k){
           
           while(q1.size()<candidates && l<=r){
               q1.push(costs[l++]);
           } 
            
            while(q2.size()<candidates && r>=l){
                q2.push(costs[r--]);
            }
            
            int min1 = q1.size()>0?q1.top():INT_MAX; 
            int min2 = q2.size()>0?q2.top():INT_MAX;
            
      
            
            if(min1>min2){
                q2.pop();
                ans+=min2;
            }
            else{
                q1.pop();
                ans+=min1;
            }
            
            
            cnt++;        
            
        }
        return ans;
    }
};