class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n=nums.size();
        vector<int> setBit(32,-1);
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            int lastInd=i;

            for(int j=0;j<32;j++){
                if(nums[i] & 1<<j){
                    setBit[j]=i;
                }
                else{
                    lastInd=max(lastInd,setBit[j]);
                }
            }

            ans[i]=lastInd-i+1;
        }

        return ans;
    }
};