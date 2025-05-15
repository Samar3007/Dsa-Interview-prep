class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans, res;
        int alt1=0, alt2=1;
        for(int i=0;i<groups.size();i++){
            if(alt1==groups[i]){
                ans.push_back(words[i]);
                alt1=!alt1;
            }
            if(alt2==groups[i]){
                res.push_back(words[i]);
                alt2=!alt2;
            }
        }
        if(ans.size()>=res.size()) return ans;
        return res;
    }
};