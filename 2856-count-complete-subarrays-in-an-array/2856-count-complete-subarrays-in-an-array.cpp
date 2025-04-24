class Solution {
public:

    int countCompleteSubarrays(vector<int>& nums) {
        int k = unordered_set<int>(nums.begin(),nums.end()).size();
        unordered_map<int, int> mpp;
        int left=0, ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++) {
            mpp[nums[i]]++;
            while (mpp.size()==k) {
                ans+=nums.size()-i;  
                mpp[nums[left]]--;
                if(mpp[nums[left]]==0) mpp.erase(nums[left]);
                left++;
            }
        }
        return ans;
    }
};