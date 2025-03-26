class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int  n = grid.size(), m = grid[0].size(), ans = 0;
        vector<int> vec;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vec.push_back(grid[i][j]);
            }
        }
        sort(vec.begin(),vec.end());
        int med = vec[vec.size()/2];
        for(int it:vec){
            if(abs(it-med)%x) return -1;
            ans += abs(it-med)/x;
        }
        return ans; 
    }
};