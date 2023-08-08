class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums,int ind){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=ind;i<nums.size();i++){
            swap(nums[i],nums[ind]);
            solve(nums,ind+1);
            swap(nums[ind],nums[i]);
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
 
        solve(nums,0);
        return ans;
        
        
    }
};