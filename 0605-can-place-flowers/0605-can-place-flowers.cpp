class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int i=1;
        flowerbed.insert(flowerbed.begin(),0);
        flowerbed.push_back(0);
        while(i+1<flowerbed.size()){
            if(flowerbed[i-1] == 0 && flowerbed[i] == 0 && flowerbed[i+1] == 0){
                n--;i++;
            }
            i++;
            if(n<=0){return true;}
        }
        return false;
        
    }
};