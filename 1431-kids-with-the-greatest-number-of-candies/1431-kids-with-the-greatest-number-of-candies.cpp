class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int maxi=*max_element(candies.begin(),candies.end());
        
        /*int maxi=0;
        for(int i=0;i<candies.size();i++){
            maxi=max(candies[i],maxi);
        }*/
        
        for(auto j:candies){
            if((j+extraCandies)>=maxi){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};