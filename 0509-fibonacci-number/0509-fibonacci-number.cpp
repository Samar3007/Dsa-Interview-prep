class Solution {
public:
    int fib(int n) {
        if(!n) return 0;
        int prev2=0, prev1=1;
        for(int i=2;i<=n;i++){
            int curr=prev1 + prev2;
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};