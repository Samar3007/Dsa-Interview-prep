class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n=endTime.size();
        vector<int> gaps(n+1);
        gaps[0]=startTime[0];
        gaps[n]=eventTime-endTime[n-1];
        for(int i=1;i<n;i++){
            gaps[i]=startTime[i]-endTime[i-1];
        }
        
        int i=0, j=0;
        int ans=0, sum=0;
        
        while(j<n+1){
            sum+=gaps[j];
            if(j-i+1 > k+1){
                sum-=gaps[i];
                i++;
            }
            j++;
            ans=max(ans,sum);
        }
        
        return ans;
    }
};