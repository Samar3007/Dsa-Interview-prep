class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==0 || n==1) return;
        k=k%n;
        reverse(nums.begin(),nums.begin()+n-k);
        reverse(nums.begin()+n-k,nums.begin()+n);
        reverse(nums.begin(),nums.begin()+n);
        return;
    }
};