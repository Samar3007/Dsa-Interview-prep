class Solution {
public:
    // int upper_bnd(vector<int>& nums, int ele, int l, int r){
    //     int mid=0, ans=nums.size();
    //     while(l<=r){
    //         mid=(l+r)/2;
    //         if(nums[mid]>ele){
    //             ans=mid;
    //             r=mid-1;
    //         }
    //         else{
    //             l=mid+1;
    //         }
    //     }
    //     return l;
    // }
    // int lower_bnd(vector<int>& nums, int ele, int l, int r){
    //     int mid=0;
    //     while(l<=r){
    //         mid=(l+r)/2;
    //         if(nums[mid]<ele){
    //             l=mid+1;
    //         }
    //         else{
    //             r=mid-1;
    //         }
    //     }
    //     return r;
    // }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++){
            // int low=lower-nums[i], high=upper-nums[i];
            // int start=lower_bnd(nums,low,i+1,n-1);
            // int end=upper_bnd(nums,high,i+1,n-1);        
            // ans+=end-start-1;
            long long high = upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-nums.begin();
            long long low = lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i])-nums.begin();
            ans+=high-low;
        }
        return ans;
    }
};