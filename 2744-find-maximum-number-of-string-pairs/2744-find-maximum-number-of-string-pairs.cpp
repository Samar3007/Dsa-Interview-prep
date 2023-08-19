class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        int cnt=0;
        
        for(int i=0;i<words.size();i++){
            for(int j=i+1;j<words.size();j++){
                swap(words[i][0],words[i][1]);
                if(words[i]==words[j]) cnt++;
                swap(words[i][0],words[i][1]);
            }
        }
        return cnt;
    }
};