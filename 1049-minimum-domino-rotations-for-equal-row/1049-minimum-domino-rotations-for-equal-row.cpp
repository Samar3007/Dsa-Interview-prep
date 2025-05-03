class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n=tops.size(), mini=INT_MAX;
        for(int i=0;i<6;i++){
            int cntT=0, cntB=0;
            int j=0;
            for(j;j<n;j++){
                if(tops[j] != i+1){
                    if(bottoms[j] == i+1) cntT++;
                    else break;
                }
            }
            if(j==n) mini=min(mini,cntT);
            j=0;
            for(j;j<n;j++){
                if(bottoms[j] != i+1){
                    if(tops[j] == i+1) cntB++;
                    else break;
                }
            }
            if(j==n) mini=min(mini,cntB);
        }
        if(mini==INT_MAX) return -1;
        return mini;
    }
};