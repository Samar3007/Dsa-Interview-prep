class Solution {
public:
   
    bool buddyStrings(string s, string goal) {
        if(s==goal){
            set<int> temp(s.begin(),s.end());
            return temp.size()<goal.size();
        }
        
        if(s.length()!=goal.length()) return false;
        
        int n=s.length();
        int i=0;
        int j=n-1;
        while(i<j && s[i]==goal[i]){
            i++;
        }
        
        while(j>i && s[j]==goal[j]){
            j--;
        }
        swap(s[i],s[j]);
        
        return s==goal;        
    }
};