class Solution {
public:
    bool isPalindrome(string s) {
        int n=s.length();
        
        if(n<2) return true;
        int l=0, r=n-1;

        while(l<r){
            while(!isalnum(s[l]) && l<r) l++;
            while(!isalnum(s[r]) && l<r) r--;
            if(tolower(s[l++]) != tolower(s[r--]))
                return false;
        } 
        return true;
    }
};