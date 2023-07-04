class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        sort(nums.begin(),nums.end());
        
        int i=0, j=2;
        while(j+1<n){
            if(nums[i]!=nums[j]) return nums[i];
            i=j+1;
            j=j+3;
        }
        return nums[n-1];
    }
};