class Solution {
public:
    bool isValid(string word) {
        bool consnt = false, vowel = false, extra = false;
        
        if(word.size()<3) return false;
        
        for(char c:word){
            int cap = c-'A', low = c-'a', num = c-'0';
            
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U') vowel = true;
            else if((cap<26 && cap>=0) || (low<26 && low>=0)) consnt = true;
            else if(num>=0 && num<10) continue;
            else return false;
        }
        
        return (vowel && consnt);
    }
};