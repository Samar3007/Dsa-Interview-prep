class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        int j=0, n=nums.size();
        long long cnt=0;
        for(int i=0;i<n;i++){
            j=i;
            while(j+1<n && nums[j]!=nums[j+1]){
                j++;
            }
            int len=j-i+1;
            cnt+=(long long)len*(len+1)/2;
            i=j;
        }
        return cnt;
    }
};