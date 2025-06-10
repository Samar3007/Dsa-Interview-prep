class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26);
        int maxiOdd=0, miniEven=INT_MAX;
        for(char c:s){
            freq[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(freq[i]!=0){
                if(freq[i]%2==0) miniEven=min(miniEven,freq[i]);
                else maxiOdd=max(maxiOdd,freq[i]);
            }

        }
        return maxiOdd-miniEven;
    }
};