class Solution {
public:
    vector<vector<int>> ans;
    void solve(vector<int>& nums, vector<int>& arr,int freq[]){
        if(arr.size()==nums.size()){
            ans.push_back(arr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!freq[i]){
                arr.push_back(nums[i]);
                freq[i]=1;
                solve(nums,arr,freq);
                arr.pop_back();
                freq[i]=0;
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        int freq[nums.size()];
        for(int i=0;i<nums.size();i++){
            freq[i]=0;
        }
        vector<int> arr;
        solve(nums,arr,freq);
        return ans;
        
        
    }
};