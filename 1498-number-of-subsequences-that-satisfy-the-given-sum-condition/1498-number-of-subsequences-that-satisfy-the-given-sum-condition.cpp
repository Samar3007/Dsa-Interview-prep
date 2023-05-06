class Solution {
public:
    
    long power(long a, long n, long p){
        long res=1;
        if(n==1) return a;
        if(n==0) return 1;
        if(n%2==0){
            res=power(a,n/2,p);
            res=res*res;
        }
        else{
            res=power(a,n-1,p);
            res=(res*a);
        }
        return res%p;
    }
    
    
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int l=0, h=nums.size()-1, mod=1000000007;
        int ans=0;
        while(l<=h){
            if(nums[l]+nums[h]<=target){
                ans+=(power(2,h-l,mod));
                ans=ans%mod;
                l++;
            }
            else h--;
        }
        return ans;
    }
};