class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows<=1) return s;
        
        vector<string> vect(numRows,"");
        int row=0, step=0;
        
        for(int i=0;i<s.length();i++){
            vect[row]+=s[i];
            if(row==0) step=1;
            if(row==numRows-1) step=-1;;
            row+=step;
        }
        
        string res="";
        for(auto c:vect){
            res+=c;
        }
        
        return res;
    }
};