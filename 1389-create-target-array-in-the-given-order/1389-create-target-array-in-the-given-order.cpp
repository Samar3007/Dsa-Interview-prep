class Solution {
public:
    void solve(int val, vector<int>& ans, int index){
        for(int i=ans.size()-1;i>index;i--){
            ans[i]=ans[i-1];
        }
        ans[index]=val;
        return;
    }
    
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int n=nums.size();
        vector<int> ans(n,-1);
       
        for(int i=0;i<n;i++){
            solve(nums[i], ans, index[i]);
        }
        
        return ans;
    }
};