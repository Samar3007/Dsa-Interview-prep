class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ans=0;
        int m=grid.size();
        int n=grid[0].size();
        int i=m-1;
        int j=0;
        while (i >= 0 && j < n) {
            if(grid[i][j] < 0) {
                ans += n - j;
                --i;
            }
            else{
                ++j;
            }
        }

        return ans;
        
            
    }
};