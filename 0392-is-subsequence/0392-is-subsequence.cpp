class Solution {
public:
    bool isSubsequence(string s, string t) {
        
        int i=0,j=0; 
        int n1= s.length();
        int n2= t.length();
        if(n2<n1) return false;
        if(s==t) return true;
        while(i<n2){
            if(s[j]==t[i]){
                i++;j++;
            }
            else{
                i++;
            }
            if(j==n1) return true;
        }
        return false;
        
    }
};