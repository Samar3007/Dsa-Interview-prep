class Solution {
public:
    int solve(int num){
        int sum=0;
        while(num){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        int freq[37]={0};
        if(n<10) return n;
        for(int i=1;i<=n;i++){
            freq[solve(i)]++;
        }
        int maxi = 0;
        for(int i=0;i<37;i++){
            maxi=max(maxi,freq[i]);
        }
        int ans=0;
        for(int i=0;i<37;i++){
            if(freq[i]==maxi) ans++;
        }
        return ans;
    }
};