class Solution {
public:
    bool areNumbersAscending(string s) {
        int ans=-1;
        vector<int> res;
        int i=0, n=s.length();
        for(;i<n;i++){
            if(isdigit(s[i])){
                string temp;
                while(i<n && isdigit(s[i])){
                    temp+=s[i++];
                }
                res.push_back(stoi(temp));
               
            }
        }
        
        for(int it:res){
            if(ans>=it) return false;
            ans=it;
        }
        return true;
    }
};



