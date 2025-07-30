class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxi=*max_element(nums.begin(), nums.end());
        int ans=0;
        
        for(int i=0;i<n;i++){

            if(nums[i]==maxi){
                int cnt=0;
                while(i<n && maxi==nums[i]){
                    cnt++;
                    i++;
                }
                
                ans=max(cnt,ans);
            }

        }
        
        return ans;
    }
};