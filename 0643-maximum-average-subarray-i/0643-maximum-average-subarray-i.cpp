class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxi=-1000;
        double sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        maxi=max(maxi,sum/k);
        int j=k;
        while(j<nums.size()){
            sum=sum-nums[j-k]+nums[j];
            maxi=max(sum/k,maxi);
            j++;
        }
        return maxi;
    }
};