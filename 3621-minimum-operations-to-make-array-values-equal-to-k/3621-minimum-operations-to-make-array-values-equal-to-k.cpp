class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        if(nums[0]<k) return -1;
        if(nums[nums.size()-1] == k) return 0;
        int i = nums.size()-1, cnt = 0;
        while(i>=0){
            int curr = nums[i];
            while(i>=0 && nums[i] == curr){
                i--;
            }
            cnt++;
        }
        return nums[0] == k ? cnt-1: cnt;
    }
};