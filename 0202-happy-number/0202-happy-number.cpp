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
        if(n<=0) return false;
        
        int slow=n, fast=square(n);
        if(slow==1 || fast==1) return true;
        
        while(slow!=fast){
            slow=square(slow);
            fast=square(square(fast));
            if(slow==1 || fast==1) return true;
        }
        
        
        return false;
    }
};