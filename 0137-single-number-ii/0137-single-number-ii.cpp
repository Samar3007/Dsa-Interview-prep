class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<32;i++){
            int sum=0;
            for(int x:nums){
                x=x>>i;
                sum+=x&1;
            }
            sum=sum%3;
            ans|=sum<<i; 
        }
        return ans;
    }
};

