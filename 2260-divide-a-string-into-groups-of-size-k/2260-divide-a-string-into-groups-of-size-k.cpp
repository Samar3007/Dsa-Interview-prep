class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string curr= "";
        for(char c:s){
            curr+=c;
            if(curr.size()==k){
                ans.push_back(curr);
                curr="";
            }
        }
        int n=curr.size();
        if(n!=0){
            while(n!=k){
                curr+=fill;
                n++;
            }
            ans.push_back(curr);
        }
        return ans;
    }
};