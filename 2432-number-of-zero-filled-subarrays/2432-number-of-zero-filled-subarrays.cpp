class Solution {
public:
    long long solve(long long cnt){
        long long res=0;
        res=(cnt*(cnt+1))/2;
        return res;
    }
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int i=0, n=nums.size();

        while(i<n){
            long long cnt=0;
            if(nums[i]==0){
                while(i<n && nums[i]==0){
                    cnt++;
                    i++;
                }
                ans+=solve(cnt);
            }
            else i++;
        }
        return ans;
    }
};