class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> ans;
        int n=candies.size();
        int maxi=*max_element(candies.begin(),candies.end());
        
        /*int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(candies[i],maxi);
        }*/
        
        for(int j=0;j<n;j++){
            if((candies[j]+extraCandies)>=maxi){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};