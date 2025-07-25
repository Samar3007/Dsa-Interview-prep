class Solution {
public:
    int maxSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans=0, n=nums.size();
        if(nums[n-1]<=0) return nums[n-1];

        int i=n-1;

        while(i>=0){
            int curr=nums[i];
            if(curr<=0) break;
            
            ans+=curr;
            
            while(i>=0 && nums[i]==curr){
                i--;
            }
        }
        return ans;
    }
};