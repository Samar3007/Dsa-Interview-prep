class Solution {
public:
    string reverseWords(string s){
        int i=0, j=0, start=0;
        int len = s.length();

        
        while (i < len) {
            while(i<len && s[i]==' ') i++;
            
            if (i < len && j > 0){
                s[j++] = ' ';
            }
            start=j;
            while(i<len && s[i]!=' ') s[j++]=s[i++];
            
            reverse(s.begin()+start, s.begin()+j);
        }
        s.resize(j);
        reverse(s.begin(),s.end());


        return s;
    }
};