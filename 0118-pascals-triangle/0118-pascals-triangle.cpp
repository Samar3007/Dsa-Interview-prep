class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> result;
        vector<int> prev={1};
        result.push_back(prev);

        for(int i=1;i<n;i++){
            vector<int> curr(i+1,1);
            for(int j=1;j<i;j++){
                curr[j]=prev[j-1]+prev[j];
            }
            prev=curr;
            result.push_back(curr);
        }
        return result;
    }
};