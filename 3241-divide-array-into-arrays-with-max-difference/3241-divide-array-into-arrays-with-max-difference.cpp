class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        if(n<3) return {};
        vector<vector<int>> vec;
        int i=0;
        for(;i<n;i+=3){
            if(nums[i+2]-nums[i]<=k) vec.push_back({nums[i], nums[i + 1], nums[i + 2]});
            else return {};
        }
        return vec;
    }
};