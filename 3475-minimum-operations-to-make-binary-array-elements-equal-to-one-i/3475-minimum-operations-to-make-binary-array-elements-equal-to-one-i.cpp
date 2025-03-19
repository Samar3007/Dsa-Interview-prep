class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size(), cnt=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0 and i+2<n){
                nums[i]=1;
                if(nums[i+1]) nums[i+1]=0;
                else nums[i+1]=1;
                if(nums[i+2]) nums[i+2]=0;
                else nums[i+2]=1;
                cnt++;
            }
        }
        for(int i=0;i<n;i++){
            if(nums[i]==0) return -1;
        }
        return cnt;
    }
};