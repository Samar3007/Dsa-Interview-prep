class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;
        for(int i=0;i<n;i++){
            int cnt=1;
        
            while(i+1<n && nums[i+1]>nums[i]){
                cnt++;
                i++;
            }
            maxi = max(maxi,cnt);
        }
        for(int i=0;i<n;i++){
            int cnt=1;
            while(i+1<n && nums[i+1]<nums[i]){
                cnt++;
                i++;
            }
            maxi = max(maxi,cnt);
        }
        return maxi;
    }
};