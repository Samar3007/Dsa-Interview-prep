class Solution {
public:
    int solve(vector<int>& nums, int ind, int target){
        if(ind==nums.size()){
            if(target==0) return 1;
            return 0;
        }
      
        int l=solve(nums,ind+1,target-nums[ind]);
        int r=solve(nums,ind+1,target+nums[ind]);
        return l+r;
    }
    
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        
        return solve(nums,0,target);
    }
};