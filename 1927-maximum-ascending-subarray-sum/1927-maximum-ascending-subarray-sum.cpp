class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int maxi = 0, n = nums.size();
        for(int i=0;i<n;i++){
            int sum = nums[i];
            while(i+1<n && nums[i+1]>nums[i]){
                sum+=nums[i+1];
                i++;
            }
            maxi = max(maxi,sum);
        }
        return maxi;
    }
};