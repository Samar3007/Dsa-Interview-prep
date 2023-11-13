class Solution {
public:
    string sortVowels(string s) {
        priority_queue<int,vector<int>, greater<int>> pq;
        for(auto c:s){
            if(c=='A' || c=='E' || c=='I' || c=='O' || c=='U' || c=='a' || c=='e' || c=='i' || c=='o' || c=='u'){
                pq.push(c);    
            }
        }
        for(int i=0;i<s.size();i++){
            if(s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' || s[i]=='U' || s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u'){
                s[i]=pq.top();    
                pq.pop();
            }
        }
        return s;
    }
};