class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX, n = blocks.size(), cnt = 0;
        for(int i=0;i<k;i++){
            if(blocks[i]=='W') cnt++;
        }
        ans=min(ans,cnt);
        for(int j=k;j<n;j++){
            if(blocks[j-k]=='W') cnt--;
            if(blocks[j]=='W') cnt++;
            ans=min(ans,cnt);
        }
        return ans;
    }
};