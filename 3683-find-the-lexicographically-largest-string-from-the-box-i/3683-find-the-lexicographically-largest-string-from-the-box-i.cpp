class Solution {
public:
    string answerString(string word, int numFriends) {
        string maxi;
        int n=word.size();
        if(numFriends==1) return word;
        for(int i=0;i<n;i++){
            string temp;
            if(n>(i+n+1-numFriends)) temp = word.substr(i,n+1-numFriends);
            else temp = word.substr(i);
        
    
            if(string(maxi) < string(temp)){
                maxi=temp;
            }
        }
        return maxi;
    }
};