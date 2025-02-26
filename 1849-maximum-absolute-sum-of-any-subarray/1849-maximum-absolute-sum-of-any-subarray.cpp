class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxi=-1e4-1, mini=1e4+1;
        int i=0, posSum=0, negSum=0;
        while(i<nums.size()){
            posSum+=nums[i];
            negSum+=nums[i];
            if(negSum>0) negSum=0;
        
            if(posSum<0) posSum=0;
            
            mini=min(mini,negSum);
            maxi=max(maxi,posSum);
            i++;
        }
        return max(maxi,abs(mini));
    }
};