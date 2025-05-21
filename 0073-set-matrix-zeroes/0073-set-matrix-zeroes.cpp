class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n=matrix.size(), m=matrix[0].size();
        vector<pair<int,int>> zer;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]==0) zer.push_back({i,j});
            }
        }
        for(auto it:zer){
            for(int j=0;j<m;j++){
                matrix[it.first][j]=0;
            }
            for(int i=0;i<n;i++){
                matrix[i][it.second]=0;
            }
        }
        return;
    }
};