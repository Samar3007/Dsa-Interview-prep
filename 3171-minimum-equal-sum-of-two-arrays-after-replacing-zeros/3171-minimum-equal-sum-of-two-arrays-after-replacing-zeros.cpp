class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        int cntZ1=0, cntZ2=0;
        long long ans=0, sum1=0, sum2=0;
        for(int it:nums1){
            if(it==0){
                cntZ1++;
                sum1++;
            }
            sum1+=it;
        }
        for(int it:nums2){
            if(it==0){
                cntZ2++;
                sum2++;
            }
            sum2+=it;
        }

        
        if((sum1>sum2 && cntZ2==0) || (sum1<sum2 && cntZ1==0)) return -1;
        
        ans=max(sum2,sum1);
        
        return ans;
    }
};