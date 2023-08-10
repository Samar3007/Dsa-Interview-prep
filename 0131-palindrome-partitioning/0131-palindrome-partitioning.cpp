class Solution {
public:
    bool isPalindrom(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
        
    }
    void solve(int ind , string s , vector<vector<string>>& ans, vector<string>& pal){
        if(ind==s.size()){
            ans.push_back(pal);
            return;
        }
        for(int i=ind;i<s.size();i++){
            
            if(isPalindrom(s,ind,i)){
                pal.push_back(s.substr(ind,i-ind+1));
                solve(i+1,s,ans,pal);
                pal.pop_back();
            }
            
        }

    }
    
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> pal;
        solve(0,s,ans,pal);
        return ans;
    }
};