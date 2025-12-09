class Solution {
public:
    int mod = 1e9+7;

    long solve(vector<int>& nums, unordered_map<int, vector<int>>& mpp, int i){
        
        int n=mpp[2*nums[i]].size();

        int ind=lower_bound(mpp[2*nums[i]].begin(), mpp[2*nums[i]].end(), i)-mpp[2*nums[i]].begin();

        if(ind==0) return 0;
        long res=(n-ind)*ind;
        return res;
    }
    
    int specialTriplets(vector<int>& nums) {
        unordered_map<int, vector<int>> mpp;
        
        long ans=0, cnt=0;

        for(int i=0;i<nums.size();i++){
            if(nums[i]!=0) mpp[nums[i]].push_back(i);
            else cnt++;
        }
        
        for(int i=0;i<nums.size();i++){
            int prod=0;
            int ele=2*nums[i];
            if(mpp.find(ele) != mpp.end()) prod=solve(nums,mpp,i);
            ans=(ans+prod)%mod;    
        }
        
        long res=0;
        cnt--;
        for(int i=0;i<cnt;i++){
            res=(res+(cnt-i)*i)%mod;
        }
        ans=(ans+res)%mod;    

        return ans;
    }
};