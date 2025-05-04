class Solution {
public:

    int solve(int num){
        int ans=0;
        while(num>0){
            ans+=num;
            num--;
        }
        return ans;
    }
    int numEquivDominoPairs(vector<vector<int>>& d) {
        int n=d.size(), i=0, ans=0;
        for(int j=0;j<n;j++){
            sort(d[j].begin(),d[j].end());    
        }
        sort(d.begin(),d.end());
        while(i<n){
            auto curr=d[i];
            int cnt=0;
            while(i<n && curr==d[i]){
                cnt++;
                i++;
            }
            ans+=solve(cnt-1);
        }
        return ans;
    }
};