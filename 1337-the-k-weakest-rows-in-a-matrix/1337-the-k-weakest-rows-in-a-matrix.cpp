class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> cnt;
        for(int i=0;i<mat.size();i++){
            int ones=0;
            for(int j=0;j<mat[i].size();j++){
                if(mat[i][j]==1) ones++;
            }
            cnt.push({ones,i});
        }
        vector<int> ans;
        
        while(k--){
            ans.push_back(cnt.top().second);
            cnt.pop();
        }
        
        return ans;
    }
};