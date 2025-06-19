class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n= nums.size();
        sort(nums.begin(), nums.end());
        int mini=nums[0], ans=1, maxi=nums[0];
        for(int& a:nums){
            mini=min(mini,a);
            maxi=max(maxi,a);
            if(maxi-mini>k){
                ans++;
                mini=a;
            }
        }
        return ans;
    }
};