class Solution {
public:
    int binary(int l, int r, int k, vector<long>& pref, int ele, int ind){
        int curr=0;
        while(l<=r){
            int mid=(l+r)/2;
            long sum=long(ind-mid+1)*long(ele);
            long prefSum=(pref[ind+1]-pref[mid]);
            long diff=sum-prefSum;
            if(diff<=k){
                r=mid-1;
                curr=max(curr,ind-mid+1);
            }
            else{
                l=mid+1;
            }
        }
        return curr;
    }

    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int maxi=1, n=nums.size();
        vector<long> pref(n+1,0);
        for(int i=0;i<n;i++){
            pref[i+1]=pref[i]+nums[i];
        }

        for(int i=0;i<n;i++){
            int curr=0;
            curr=binary(0,i,k,pref,nums[i],i);
            maxi=max(curr,maxi);
        }
        return maxi;
    }
};