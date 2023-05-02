class Solution {
public:
    int arraySign(vector<int>& nums) {
        int i=0,count;
        int n=nums.size();
        while(i<n){
            if(nums[i]<0) count++;
            else if(nums[i]==0) return 0;
            i++;
            
        }
        if(count%2==0) return 1;
        return -1;
    }
};