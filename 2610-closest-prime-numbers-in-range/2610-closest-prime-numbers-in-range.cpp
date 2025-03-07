class Solution {
public:
    bool solve(int num){
        for(int i=2;i*i<=num;i++){
            if(num%i==0) return false;
        }
        return true;
    }

    vector<int> closestPrimes(int left, int right) {
        int prev=-1, mini = INT_MAX;
        vector<int> ans(2,-1);
        for(int i=max(2,left);i<=right;i++){
            if(solve(i)){
                if(prev!=-1){
                    int diff = i-prev;
                    if(mini>diff){
                        ans[0]=prev;
                        ans[1]=i;
                        mini=diff;
                    }
                }
                prev=i;
            }
        }
    return ans;
    }
};