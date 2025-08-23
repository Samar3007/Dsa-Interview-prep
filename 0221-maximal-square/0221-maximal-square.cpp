class Solution {
public:

    bool check(int res, int i, int j, vector<vector<char>>& matrix){
        bool isValid = true;
        for(int r=0;r<=res;r++){
            if(matrix[i+r][j+res] == '0'){
                isValid=false;
                break;
            }
        }
        for(int c=0;c<=res;c++){
            if(matrix[i+res][j+c] == '0'){
                isValid=false;
                break;
            }
        }
        return isValid;
    }

    int solve(int i, int j, vector<vector<char>>& matrix, int n, int m){
        int res=0;
        while(i+res+1<n && j+res+1<m && check(res+1,i,j,matrix)){
            res++;
        }
        return res;
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();

        int maxi=0;
        bool isOne=false;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1' && n-i>maxi){
                    maxi=max(maxi,solve(i,j,matrix,n,m));
                    isOne=true;
                }
            }
        }
        if(!isOne) return 0;
        return (maxi+1)*(maxi+1);
    }
};