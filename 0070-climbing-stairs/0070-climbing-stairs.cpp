class Solution {
public:

    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        int prev2=1, prev1=1;
        int curr=1;
        for(int i=2;i<=n;i++){
            curr=prev1+prev2;
            prev2=prev1;
            prev1=curr;
        }
        return curr;
    }
};