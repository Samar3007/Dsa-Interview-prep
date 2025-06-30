class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<long,int> mpp;
        for(int it:nums){
            mpp[it]++;
        }
        int maxi=0;
        long prev=-1e9-2;
        mpp[prev]=-1e5;
        for(auto it:mpp){
            int curr=it.first;
            if(curr-prev==1) maxi=max(maxi,mpp[curr]+mpp[prev]);
            prev=curr;
        }
        return maxi;
    }
};