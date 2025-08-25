class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int i=0, j=0, m=mat.size(), n=mat[0].size();
        bool way=false;
        vector<int> ans;

        while(ans.size()!=n*m){
            
            while(ans.size()!=n*m && !way){
                if(j+1==n || i-1<0){
                    ans.push_back(mat[i][j]);
                
                    if(j+1==n){
                        i++;
                    }
                    else{
                        j++;
                    }
                    way=!way;
                }
                
                else{
                    ans.push_back(mat[i][j]);
                    i--;
                    j++;
                }
            }
            
            while(ans.size()!=n*m && way){
                if(i+1==m || j-1<0){
                    ans.push_back(mat[i][j]);
                    if(i+1==m){
                        j++;
                    }
                    else{
                        i++;
                    }
                    way=!way;
                }
                
                else{
                    ans.push_back(mat[i][j]);
                    i++;
                    j--;
                }
            }
        }
        return ans;
    }
};