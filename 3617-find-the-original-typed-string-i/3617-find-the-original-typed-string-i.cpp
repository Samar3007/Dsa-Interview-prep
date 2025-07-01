class Solution {
public:
    int possibleStringCount(string word) {
        int n=word.size(), i=0;
        int ans=0;
        while(i<n){
            int j=i;
            while(j<n && word[i]==word[j]){
                j++;
            }
            ans+=j-i-1;
            i=j;
        }
        return ans+1;
    }
};