class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        char ch[26];
        for (int i=0;i<26;i++){
            ch[i] = 'a'+i;
        }

        for(int i=0;i<s1.size();i++){
            char lower = min(ch[s1[i]-'a'], ch[s2[i]-'a']);
            char higher = max(ch[s1[i]-'a'], ch[s2[i]-'a']);
            
            for(int j=0;j<26;j++){
                if(ch[j] == higher){
                    ch[j] = lower;
                }
            }
        }
        
        for(int i=0;i<baseStr.size();i++){
            baseStr[i] = ch[baseStr[i]-'a'];
        }

        return baseStr;
    }
};