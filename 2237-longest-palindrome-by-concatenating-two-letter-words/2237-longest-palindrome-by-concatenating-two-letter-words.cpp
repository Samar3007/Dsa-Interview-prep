class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int ans=0;
        unordered_map<string,int> mpp;
        for(auto &it:words){
            mpp[it]++;
        }
        int midTaken = false;

        for(auto &it:mpp){
            string rev = it.first;
            reverse(rev.begin(),rev.end());
            if(rev==it.first){
                if(!midTaken && mpp[it.first]%2){
                    midTaken = true;
                    ans+=2;
                }
                ans+=(mpp[it.first]/2)*4;
            }
            else if(it.first<rev && mpp.count(rev)){
                int freq = min(mpp[it.first],mpp[rev]);
                ans+=freq*4;
            }
        }
        return ans;
    }
};