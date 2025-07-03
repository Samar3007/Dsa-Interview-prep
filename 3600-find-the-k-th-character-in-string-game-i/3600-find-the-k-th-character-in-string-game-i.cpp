class Solution {
public:
    char kthCharacter(int k) {
        int n=1;
        string st="a";
        while(st.size()<k){
            string curr="";
            for(char c:st){
                curr+=char(((c+1)-'a')%26 +'a');
            }
            st+=curr;
        }
        return st[k-1];
    }
};