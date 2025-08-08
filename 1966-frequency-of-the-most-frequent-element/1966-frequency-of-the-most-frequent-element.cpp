class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxi=1, n=nums.size();
        int i=0, j=0;
        long currSum=0;
        
        while(j<n){
            currSum+=nums[j];
            int target=nums[j];
            long targetSum=long(j-i+1)*target;
            long diff=targetSum-currSum;

            while(diff>k){
                currSum-=nums[i];
                i++;
                targetSum=long(j-i+1)*target;
                diff=targetSum-currSum;
            }
            maxi=max(maxi,j-i+1);
            j++;
        }
        
        return maxi;
    }
};