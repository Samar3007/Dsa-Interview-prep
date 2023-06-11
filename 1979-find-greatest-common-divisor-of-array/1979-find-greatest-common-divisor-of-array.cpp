class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini=*min_element(nums.begin(),nums.end());
        int maxi=*max_element(nums.begin(),nums.end());
        int ans=mini;
    
        while(ans>0){
            if(maxi%ans == 0 && mini%ans == 0){
                break;
            }
            else ans--;
        }
        return ans;
        
    }
};