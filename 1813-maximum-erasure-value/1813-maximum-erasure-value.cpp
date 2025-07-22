class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_map<int,int> mpp;
        int ans=INT_MIN, sum=0;
        
        int curr=0, n=nums.size(), i=0;
        
        while(curr<n){
            mpp[nums[curr]]++;
            sum+=nums[curr];
            while(mpp[nums[curr]]>1){
                sum-=nums[i];
                mpp[nums[i++]]--;
            }
            ans=max(sum,ans);
            curr++;
        }
        
        return ans;
    }
};