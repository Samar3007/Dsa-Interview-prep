class Solution {
public:
    
    int tribonacci(int n) {
        int curr = 0;
        if(n==2 || n==1) return 1;
        if(n==0) return 0;
        int prev3 = 0;
        int prev2 = 1;
        int prev1 = 1;
       
        for(int i=3;i<=n;i++){
            curr= prev3 + prev2 + prev1;
            prev3=prev2;
            prev2=prev1;
            prev1=curr;
        }
    
        return curr;
    }
};