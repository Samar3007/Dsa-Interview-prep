class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int maxi=0, n=nums.size(), start=0;
        int bitsUnion=0;
        for(int i=0;i<n;i++){
            
            while((bitsUnion & nums[i]) !=0) bitsUnion^=nums[start++];
            bitsUnion|=nums[i];        
            maxi=max(maxi,i-start+1);
                
        }
        return maxi;
    }
};