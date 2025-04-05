class Solution {
public:
    void solve(int i, vector<int>& nums, vector<vector<int>>& res, int n, vector<int>& curr){
        if(i==n){
            res.push_back(curr);
            return;
        }
        curr.push_back(nums[i]);
        solve(i+1,nums,res,n,curr);
        curr.pop_back();
        solve(i+1,nums,res,n,curr);
    }
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> curr;
        int n = nums.size();
        solve(0,nums,res,n,curr);
        int ans = 0;
        for(auto it:res){
            int sum = 0;
            for(int num:it){
                sum^=num;
            }
            ans+=sum;
        }
        return ans;
    }
};