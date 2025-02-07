class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        int cnt = 0, n = queries.size();
        vector<int> ans;
        unordered_map<int,int> clr, ball;
        for(int i=0;i<n;i++){
            int x = queries[i][0];
            int y = queries[i][1];
            if(ball.find(x) != ball.end()){
                int prevclr = ball[x];
                clr[prevclr]--;
                if(clr[prevclr] == 0){
                    clr.erase(prevclr);
                }
            }
            ball[x] = y;
            clr[y]++;
            ans.push_back(clr.size());
        }
        return ans;
    }
};