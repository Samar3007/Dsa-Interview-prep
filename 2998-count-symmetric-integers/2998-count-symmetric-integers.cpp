class Solution {
public:
    bool solve(int num, int len){
        if(len==2){
            int first = num%10;
            int second = num/10;
            if(first == second) return true;
        }
        else{
            int first = num%10;
            num/=10;
            first += num%10;
            num/=10;
            int second = num%10;
            num/=10;
            second += num%10;
            if(first == second) return true;
        }
        return false;
    }

    int countSymmetricIntegers(int low, int high) {
        int cnt=0, i=max(11,low);
        while(i<=min(99,high)){
            if(solve(i,2)) cnt++;
            i++;
        }
        i=max(1000,low);
        

        while(i<=min(high,9999)){
            if(solve(i,4)) cnt++;
            i++;
        }
        return cnt;
    }
};