class Solution {
public:
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int i=0, j=n-1;

        vector<vector<int>> ans (n, vector<int>(n));

        while(i!=n-1){
            int stRow=i, stCol=j;
            vector<int> temp;
            while(stRow<n && stCol<n){
                temp.push_back(grid[stRow][stCol]);
                stRow++;
                stCol++;
            }
            
            stRow=i, stCol=j;
            
            if(i<j){
                sort(temp.begin(), temp.end());
            }
            else{
                sort(temp.begin(), temp.end(), greater<int>());
            }
            
            int l=0;
            while(stRow<n && stCol<n){
                ans[stRow][stCol]=temp[l++];
                stRow++;
                stCol++;
            }

            if(j==0){
                i++;
            }
            else j--;
        }
        
        ans[n-1][0]=grid[n-1][0];

        return ans;
    }
};