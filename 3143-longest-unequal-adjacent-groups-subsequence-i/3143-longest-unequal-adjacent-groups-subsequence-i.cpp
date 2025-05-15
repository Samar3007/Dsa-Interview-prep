class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans;
        int alt=0;
        for(int i=0;i<groups.size();i++){
            if(alt==groups[i]){
                ans.push_back(words[i]);
                alt=!alt;
            }
        }
        vector<string> res;
        alt=1;
        for(int i=0;i<groups.size();i++){
            if(alt==groups[i]){
                res.push_back(words[i]);
                alt=!alt;
            }
        }
        if(ans.size()>=res.size()) return ans;
        return res;
    }
};