class Solution {
public:
    bool isPalindrome(string s) {
        string temp;
        for(char c:s){
            c=tolower(c);
            if((c-'a'>=0 && c-'a'<26) || (c-'0'>=0 && c-'0'<10)){
                temp+=c;
            }
        }
        s=temp;
        int n=s.size();
        int l=0, r=n-1;
        while(l<r && s[l]==s[r]){
            l++;
            r--;
        }
        if(l>=r) return true;
        return false;
    }
};