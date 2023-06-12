class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rsum=0;
      
        for(int i=0;i<nums.size();i++){
            rsum+=nums[i];
        }
        int lsum=0;
        for(int j=0;j<nums.size();j++){
            
            rsum-=nums[j];
            if(lsum==rsum) return j;
            lsum+=nums[j];
            
        }
        return -1;
    }
};