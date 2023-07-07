class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int left=0, cnt=0, n=answerKey.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(answerKey[i]=='F')
                cnt++;
            while(cnt>k){
                if(answerKey[left]=='F') cnt--;
                left++;
            }
            ans=max(i-left+1,ans);
        }
        
        cnt=0;left=0;
        for(int i=0;i<n;i++){
            if(answerKey[i]=='T'){
                cnt++;
            }
            while(cnt>k){
                if(answerKey[left]=='T') cnt--;
                left++;
            }
            
            ans=max(i-left+1,ans);
        }
        return ans;
    }
        
};
    
    


