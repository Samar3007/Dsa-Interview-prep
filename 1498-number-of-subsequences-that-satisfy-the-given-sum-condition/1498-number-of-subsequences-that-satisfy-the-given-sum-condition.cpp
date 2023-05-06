class Solution {
public:
    
    long power(long a, long n, long p){
        long res=1;
        while(n){
            if(n%2==1){
                res=(res*a)%p;
                n--;
            }
            else{
                a=(a*a)%p;
                n=n/2;
            }
        }
        return res;
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