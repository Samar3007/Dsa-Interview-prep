class Solution {
public:
    int maxVowels(string s, int k) {
        unordered_set<char> vowels={'a','i','e','o','u'};
        int maxi=0;
        int count=0;
        for(int i=0;i<k;i++){
           if(vowels.find(s[i]) != vowels.end()){
               count++;
           }
        }
        maxi=count;
        for(int j=k;j<s.length();j++){
            if(vowels.find(s[j]) != vowels.end()){
               count++;
            }
            if(vowels.find(s[j-k])!=vowels.end()){
                count--;
            }
            maxi=max(count,maxi);
        }
        return maxi;
    }
};