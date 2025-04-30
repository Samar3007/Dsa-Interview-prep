class Solution {
public:
    int solve(int it){
        int dig=0;
        while(it){
            it/=10;
            dig++;
        }
        if(dig%2==0) return 1;
        return 0;
    }
    int findNumbers(vector<int>& nums) {
        int cnt=0;
        for(int it:nums){
            cnt+=solve(it);
        }
        return cnt;
    }
};