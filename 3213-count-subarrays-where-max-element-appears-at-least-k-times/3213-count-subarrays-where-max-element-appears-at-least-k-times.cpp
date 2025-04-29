class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long ans=0;
        int maxi = 0, n = nums.size();
        for(int it:nums){
            maxi=max(maxi,it);
        }
        int i=0, cnt=0, left=0;
        while(i<n){
            if(nums[i]==maxi) cnt++;
            while(cnt>=k){
                ans+=(n-i);
                if(nums[left]==maxi) cnt--;
                left++;
            }
            i++;
        }
        return ans;
    }
};