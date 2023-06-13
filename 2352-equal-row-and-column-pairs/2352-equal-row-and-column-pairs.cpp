class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        vector<string> row;
        vector<string> col;
        for(int i=0;i<n;i++){
            string st="";
            
            for(int j=0;j<n;j++){
                st+=to_string(grid[i][j])+",";
            }
            row.push_back(st);
        }
        
        for(int i=0;i<n;i++){
            string st="";
            for(int j=0;j<n;j++){
                st+=to_string(grid[j][i])+",";
            }
            col.push_back(st);
        }
                         
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(row[i]==col[j]) ans++;
            }
        }
         
        return ans;
    }
};