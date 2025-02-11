class Solution {
public:
    string removeOccurrences(string s, string part) {
        string temp = s;
        int n1 = s.size(), n2 = part.size(), i = 0, j = 0;
        while(i<n1){
            temp[j++] = s[i];
            if(j>=n2 && temp.substr(j-n2,n2) == part){
                j-=n2;
            }
            i++;
        }
        return temp.substr(0,j);
    }
};