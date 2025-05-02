class Solution {
public:
    string pushDominoes(string dominoes) {
        string s = "L" + dominoes + "R";
        int n    = s.length();
        string res = "";
        for(int i = 0, j = 1; j<n; j++) {
            if(s[j] == '.') continue;
            
            int mid = j-i-1;
            if(i > 0)
                res.push_back(s[i]);
            
            if(s[i] == s[j])
                res += string(mid, s[i]);
            else if(s[i] == 'L' && s[j] == 'R')
                res += string(mid, '.');
            else
                res += string(mid/2, 'R') + string(mid%2, '.') + string(mid/2, 'L');
            i = j;
        }
        
        return res;
    }
};
