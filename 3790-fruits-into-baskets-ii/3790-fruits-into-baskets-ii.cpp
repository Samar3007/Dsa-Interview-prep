class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size(), ans=0;
        for(int i=0;i<n;i++){
            int j=0;
            for(j;j<n;j++){
                if(fruits[i]<=baskets[j]){
                    baskets[j]=0;
                    break;
                }
            }
            if(j==n) ans++;
        }

        return ans;
    }
};