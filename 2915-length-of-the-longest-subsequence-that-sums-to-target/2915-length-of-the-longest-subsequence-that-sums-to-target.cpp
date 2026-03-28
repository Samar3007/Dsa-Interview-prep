class Solution {
public:
    int solve(vector<int>& nums, int target, int i, vector<vector<int>>& dp){
        if(target==0) return 0;

        if(target<0 || i==nums.size()){
            return -1e8;
        }
        
        if(dp[i][target]!=-1) return dp[i][target];
        int take=0;
        take=1+solve(nums,target-nums[i],i+1,dp);
        int notTake=solve(nums,target,i+1,dp);
        return dp[i][target]=max(take,notTake);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        int n=nums.size();
        vector<vector<int>> dp(1e3+1,vector<int>(1e3+1,-1));
        int ans=solve(nums,target,0,dp);
        if(ans < -1) return -1;
        return ans;
    }
};