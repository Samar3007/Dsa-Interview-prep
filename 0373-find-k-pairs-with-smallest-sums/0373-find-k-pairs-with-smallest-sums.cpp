class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        int n1=nums1.size(), n2=nums2.size();
        priority_queue<pair<int,pair<int,int>>> pq;
        int sum=0;
        
        for(int i=0;i<n1;i++){
           
            for(int j=0;j<n2;j++){
            
                sum=nums1[i]+nums2[j];
                
                if(pq.size()<k) pq.push({sum,{nums1[i],nums2[j]}});
                
                else if(sum<pq.top().first){
                    pq.pop();
                    pq.push({sum,{nums1[i],nums2[j]}});
                }
                
                else break;
                
            }
            
        }
        
        while(pq.size()){
            auto it=pq.top();
            pq.pop();
            res.push_back({it.second.first,it.second.second});
        }
        reverse(res.begin(),res.end());
        return res;
    }
};