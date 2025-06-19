class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int i=0, ans=0;
        int n= nums.size();
        sort(nums.begin(), nums.end());
        while(i<n){
            int j=i;
            while(j<n && nums[j]-nums[i]<=k){
                j++;
            }
            ans++;
            i=j;
        }
        return ans;
    }
};