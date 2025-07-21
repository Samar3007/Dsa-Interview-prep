class Solution {
public:
    string makeFancyString(string s) {
        string str="";
        int i=0;
        while(i<s.size()){
            char curr=s[i];
            int cnt=0;
            while(s[i]==curr){
                cnt++;
                i++;
                if(cnt<=2) str+=curr;
            }
        }
        return str;
    }
};