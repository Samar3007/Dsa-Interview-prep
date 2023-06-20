class Solution {
public:
    int mod=1000000007;
    vector<int> getAverages(vector<int>& nums, int k) {
        int n=nums.size(),l=2*k;
        
        vector<int> ans(n,-1);
        if(l>n) return ans;
        
        long avg=0;
        for(int i=0;i<n;i++){
            avg+=nums[i];
            if(i>=l){
                ans[i-k]= avg/(2*k+1);
                avg=avg-nums[i-l];
            }
            
        }
        
        return ans;
        
    }
};