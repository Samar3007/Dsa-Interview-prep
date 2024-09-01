class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        vector<vector<int>> vec;
        if(m*n != original.size()) return vec;
        
        int i=0;
        for(int k=0;k<m;k++){
            vec.push_back(vector<int>());
            for(int l=0;l<n;l++){
                vec[k].push_back(original[i++]);
            }
        }
        return vec;
    }
};