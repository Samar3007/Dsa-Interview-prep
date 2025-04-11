class Solution {
public:
    bool solve(int num){
        
        int first = num%10;
        num/=10;
        first += num%10;
        num/=10;
        int second = num%10;
        num/=10;
        second += num%10;
        return(first == second) ;
    }

    int countSymmetricIntegers(int low, int high) {
        int cnt=0, i=max(11,low);
        while(i<=min(99,high)){
            if(i%11==0) cnt++;
            i++;
        }
        i=max(1000,low);
        

        while(i<=min(high,9999)){
            if(solve(i)) cnt++;
            i++;
        }
        return cnt;
    }
};