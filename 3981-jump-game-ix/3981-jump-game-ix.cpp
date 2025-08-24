class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        vector<int> maxiPref(n), miniSuff(n), res(n);

        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            maxiPref[i]=maxi;
        }

        int mini=nums[n-1];
        miniSuff[n-1]=mini;

        for(int i=n-2;i>=0;i--){
            mini=min(mini,nums[i]);
            miniSuff[i]=mini;
        }

        res[n-1]=maxiPref[n-1];

        for(int i=n-2;i>=0;i--){
            res[i]=maxiPref[i];
            if(maxiPref[i]>miniSuff[i+1]) res[i]=res[i+1];
        }
        
        return res;
    }
};