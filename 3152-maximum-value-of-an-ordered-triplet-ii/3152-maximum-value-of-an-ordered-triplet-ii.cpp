class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi = 0;
        int maxCurr = 0, maxDiff = 0;
        for(int it:nums){
            maxi = max(maxi,(long long)maxDiff*it);
            maxDiff = max(maxCurr-it,maxDiff);
            maxCurr = max(maxCurr,it);
        }
        return maxi;
    }
};