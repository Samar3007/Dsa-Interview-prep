class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX;
        for(int i=0;i<=blocks.size()-k;i++){
            int cnt = 0;
            for(int j=i;j<k+i;j++){
                if(blocks[j]=='W') cnt++;
            }
            ans=min(ans,cnt);
        }
        return ans;
    }
};