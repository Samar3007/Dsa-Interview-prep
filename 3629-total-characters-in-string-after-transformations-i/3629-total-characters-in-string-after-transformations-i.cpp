class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
        int mod = 1e9+7;
        //unordered_map<char,int> mpp;
        int freq[26]={0};
        for(char &it:s){
            freq[it-'a']++;
        }
        for(int i=0;i<t;i++){
            //unordered_map<char,int> temp;
            int temp[26]={0};
            for(int j=0;j<26;j++){
                char alph=j+'a';
                if(alph!='z'){
                    temp[alph+1-'a']=(temp[alph+1-'a']+freq[j])%mod;
                }
                else{
                    temp[0]=(temp[0]+freq['z'-'a'])%mod;
                    temp[1]=(temp[1]+freq['z'-'a'])%mod;
                }
            }
            for(int k=0;k<26;k++){
                freq[k]=temp[k];
            }
        }
        int ans=0;
        for(int it:freq){
            ans=(ans+it)%mod;
        }
        return ans;
    }
};