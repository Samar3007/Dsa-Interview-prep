class Solution {
public:
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int mini=INT_MAX, n=nums.size(), i=0, sum=0, firstPos=0;
        for(;i<n;i++){
            sum+=nums[i];
            while(sum>=target){
                mini=min(mini,i-firstPos+1);
                sum-=nums[firstPos++];
            }
        }
        return mini==INT_MAX ? 0:mini;
    }
};