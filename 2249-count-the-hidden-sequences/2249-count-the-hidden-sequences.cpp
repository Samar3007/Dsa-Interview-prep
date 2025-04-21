class Solution {
public:
    int numberOfArrays(vector<int>& differences, int lower, int upper) {
        long long mini= 0, maxi=0;
        long long sum=0, ans=0;
        for(int it:differences){
            sum+=it;
            mini=min(mini,sum);
            maxi=max(maxi,sum);
        }
        long long ltDiff=mini-lower;
        long long hgDiff=upper-maxi;
        if((long long)(ltDiff+hgDiff)>=0) return ans=ltDiff+hgDiff+1;
        return 0;

    }
};