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
        vector<int> prefix(n+2);
        for(int i=1;i<n+2;i++){
            prefix[i]=prefix[i-1]+gaps[i-1];
        }
        int ans=0;
        for(int i=k+1;i<n+2;i++){
            ans=max(ans,prefix[i]-prefix[i-k-1]);
        }
        return ans;
    }
};