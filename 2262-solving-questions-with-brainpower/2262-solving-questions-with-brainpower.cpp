class Solution {
public:
    long long solve(vector<vector<int>>& Q, int i, int n, vector<long long>& dp){
        if(i>=n) return 0;
        if(dp[i] != -1) return dp[i];
        int points = Q[i][0], jump = Q[i][1];
        long long take = (long long)points+solve(Q,i+jump+1,n,dp);
        long long notTake = solve(Q,i+1,n,dp);
        return dp[i] = max(take,notTake);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n+1,-1);
        return solve(questions, 0, n, dp);
    }
};