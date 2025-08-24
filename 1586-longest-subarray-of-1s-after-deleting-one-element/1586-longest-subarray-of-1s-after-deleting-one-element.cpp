class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxi=0, cnt=0;
        int i=0, j=0, n=nums.size();
        
        while(i<n){
            if(nums[i]==0) cnt++;
        
            while(j<n && cnt>1){
                if(nums[j]==0) cnt--;
                j++;
            }
            
            maxi=max(maxi,i-j);
            i++;
        }
        
        return maxi;
    }
};