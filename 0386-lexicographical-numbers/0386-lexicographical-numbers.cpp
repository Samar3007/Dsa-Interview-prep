class Solution {
public:
    void dfs(int n, int curr, vector<int>& ans){
        if(curr>n) return;
        ans.push_back(curr);
        for(int j=0;j<=9;j++){
            int newCurr = curr*10+j;            
            dfs(n,newCurr,ans);
        }
    }

    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            dfs(n,i,ans);
        }
        return ans;
    }
};