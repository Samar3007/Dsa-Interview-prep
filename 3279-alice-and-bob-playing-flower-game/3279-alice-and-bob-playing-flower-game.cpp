class Solution {
public:
    long long flowerGame(int n, int m) {
        long long cntOddY=m/2, cntEvenY=m/2;
        long long cntOddX=n/2, cntEvenX=n/2;
        if(m%2) cntOddY++;
        if(n%2) cntOddX++;

        long long ans=0;
        ans=cntOddX*cntEvenY+cntOddY*cntEvenX;
        return ans;
    }
};