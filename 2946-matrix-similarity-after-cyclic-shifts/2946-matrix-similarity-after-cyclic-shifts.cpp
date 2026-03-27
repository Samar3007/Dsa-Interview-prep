class Solution {
public:

    bool check(vector<vector<int>>& mat, int i, int shift){

        int m = mat[0].size();

        for(int j=0;j<m;j++){
            
            int ncol = (j+shift+m)%m;

            if(mat[i][j] != mat[i][ncol]) return false;

        }

        return true;
    }

    bool areSimilar(vector<vector<int>>& mat, int k) {
        
        int m = mat[0].size(), n = mat.size();
        int shift = k%m;

        for(int i=0;i<n;i++){
            
            if(i%2) shift = 1*shift;
            else shift = -1*shift;

            if(!check(mat,i,shift)){
                return false;
            }
        }
        return true;
    }
};