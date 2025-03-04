class Solution {
public:

    bool solve(int n, int sum, int i){
        if(n==sum) return true;
        if(n<sum || i>15) return false;
        int curr = pow(3,i);
        bool noadd = solve(n,sum,i+1);
        bool add = solve(n,sum+curr,i+1);
        return noadd||add;
    }

    bool checkPowersOfThree(int n) {
        return solve(n,0,0);
    }
};