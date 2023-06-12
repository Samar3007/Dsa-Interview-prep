class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum=0;
      
        for(int i=0;i<nums.size();i++){
            sum+=nums[i];
        }
        int lsum=0,rsum=sum-nums[0];
        if(lsum==rsum) return 0;
        for(int j=0;j<nums.size()-1;j++){
            lsum+=nums[j];
            rsum-=nums[j+1];
            if(lsum==rsum) return j+1;
            
        }
        return -1;
    }
};