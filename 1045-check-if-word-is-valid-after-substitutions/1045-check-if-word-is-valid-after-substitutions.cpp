class Solution {
public:
    bool isValid(string s) {
        int i=0, j=0;
        
        while(j<s.size()){
            s[i]=s[j];
            i++;
        
            if(i>=3){
                string curr;
                curr+=s[i-3];
                curr+=s[i-2];
                curr+=s[i-1];
        
                if(curr=="abc"){
                    i=i-3;
                }
            }
            
            j++;
        }

        s.erase(s.begin()+i, s.end());

        if(s.empty()) return true;
        return false;
    }
};