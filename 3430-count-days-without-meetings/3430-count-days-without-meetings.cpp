class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        sort(meetings.begin(), meetings.end());
        int ans = 0, prev_max = 0, n = meetings.size();
        for(int i=0;i<n;i++){
            if(i<1){
                ans = meetings[0][0]-1;
                prev_max = meetings[0][1];
            }
            if(i>=1) prev_max = max(meetings[i-1][1],prev_max);
            if(meetings[i][0]>prev_max){
                ans = ans+meetings[i][0]-prev_max-1;
            }
        }
        prev_max = max(meetings[n-1][1],prev_max);
        ans = ans+days-prev_max;
        return ans;
    }
};