class Solution {
public:
    string robotWithString(string s) {
        int mini = 1000, n=s.size();
        vector<char> rightLwt(n);
        char lowest=s[n-1];
        
        for(int i=n-1;i>=0;i--){
            if(lowest>s[i]){
                lowest=s[i];
            }
            rightLwt[i]=lowest;
        }

        string t="", paper="";
        int i=0;
        
        while(i<n){
            t+=s[i];
            if(i+1<n) lowest = rightLwt[i+1];
            else lowest = rightLwt[i];
            
            while(t.size()>0 && t.back()<=lowest){
                paper+=t.back();
                t.pop_back();
            }
            i++;
        }

        while(!t.empty()){
            paper+=t.back();
            t.pop_back();
        }
        return paper;
    }
};