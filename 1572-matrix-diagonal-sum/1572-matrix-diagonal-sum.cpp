class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n=mat.size();
        if(n==0) return 0;
        int sum=0;
        int i=0;
        while(i<n){
            sum+=mat[i][i];
            sum+=mat[i][n-1-i];
            if(i==n/2 && n%2!=0) sum-=mat[i][i];
            i++;
        }
        
        return sum;
        
    }
};