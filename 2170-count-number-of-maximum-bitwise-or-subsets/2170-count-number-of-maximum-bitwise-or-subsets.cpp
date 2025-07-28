class Solution {
public:
    int solve(int i, vector<int>& nums, int maxiOR, int currOR){
        if(i==nums.size()){
            if(currOR==maxiOR) return 1;
            return 0;
        }
        int take=solve(i+1,nums,maxiOR, currOR|nums[i]);
        int noTake=solve(i+1,nums,maxiOR, currOR);
        return take+noTake;
    }

    int countMaxOrSubsets(vector<int>& nums) {
        int maxiOR = 0;
        for(int it:nums){
            maxiOR|=it;
        }
        return solve(0,nums,maxiOR,0);
    }
};