class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> setBit(32,-1);
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<32;j++){
                if(nums[i] & 1<<j){
                    setBit[j]=i;
                }
            }
            int lastInd=-1;
            for(int j=0;j<32;j++){
                if(setBit[j]!=-1) lastInd=max(lastInd,setBit[j]);
            }
            if(lastInd==-1) lastInd=i;
            ans[i]=lastInd-i+1;
        }

        return ans;
    }
};