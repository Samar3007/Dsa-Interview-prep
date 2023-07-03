class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1==s2) return true;
        int i=0, j=s1.length()-1;
        while(i<j && s1[i]==s2[i]) i++;
        while(j>i && s1[j]==s2[j]) j--;
        swap(s1[i],s1[j]);
        return s1==s2;
    }
};