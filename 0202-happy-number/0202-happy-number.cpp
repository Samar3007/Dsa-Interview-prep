class Solution {
public:
    int square(int n){
        int sum=0,mod;
        while(n){
            mod=n%10;
            sum+=mod*mod;
            n=n/10;
        }
        return sum;
    }
    
    bool isHappy(int n) {
        int slow=n, fast=n;
        
        do{
            slow=square(slow);
            fast=square(square(fast));
        }while(slow!=fast);
        
        if(slow==1) return 1;
        return 0;
    }
};