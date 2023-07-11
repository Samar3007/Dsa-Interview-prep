class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans=0;
        for(auto c:jewels){
            for(auto d:stones){
                if(c==d) ans++;
            }
        }
        return ans;
    }
};