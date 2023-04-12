class Solution {
public:
    string removeStars(string s) {
        vector<char>vec={};
        int i=0;
        while(i<s.length()){
            if(s[i]!='*'){
                vec.push_back(s[i]);
            }
            else{
                vec.pop_back();
            }
            i++;
        }
        string str(vec.begin(), vec.end());
        return str;
    }
};