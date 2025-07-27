class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int cnt=0;
        int left=0, n=nums.size();
        
        for(int i=1;i<n-1;i++){
            if(nums[i]==nums[i+1]) continue;
            if((nums[left]<nums[i] && nums[i]>nums[i+1]) || (nums[left]>nums[i] && nums[i]<nums[i+1])) cnt++;
            left=i;
        }

        return cnt;
    }
};