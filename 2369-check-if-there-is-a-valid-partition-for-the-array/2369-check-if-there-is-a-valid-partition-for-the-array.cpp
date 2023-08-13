class Solution {
public:
    
    bool solve(int ind, vector<int>& nums, vector<int>& dp){
        if(ind==nums.size()) return true;
        if(dp[ind]!=-1) return dp[ind];
        if(ind+1<nums.size() && nums[ind]==nums[ind+1]){
            if(solve(ind+2,nums,dp)) return dp[ind]=true;
        }
        if(ind+2<nums.size()){
            if(nums[ind]==nums[ind+1] && nums[ind+1]==nums[ind+2]){
                if(solve(ind+3,nums,dp)) return dp[ind]=true;
            }
            if((nums[ind+2]-nums[ind+1])==1 && (nums[ind+1]-nums[ind])==1){
                if(solve(ind+3,nums,dp)) return dp[ind]=true;
            }
        }
        
        return dp[ind]=false;
    }
    
    bool validPartition(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n+1,-1);
        return solve(0,nums,dp);
        
    }
};