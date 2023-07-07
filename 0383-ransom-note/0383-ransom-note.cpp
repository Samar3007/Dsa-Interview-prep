class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> mpp1(26), mpp2(26);
        for(char c:ransomNote){
            mpp1[c-'a']++;
        }
        for(char c:magazine){
            mpp2[c-'a']++;
        }
        for(int i=0;i<26;i++){
            if(mpp1[i]>mpp2[i]) return false; 
        }
        return true;
    }
};