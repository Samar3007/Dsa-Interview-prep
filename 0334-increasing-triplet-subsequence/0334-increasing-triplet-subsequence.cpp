class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int one = INT_MAX, two = INT_MAX;
        for (int in=0;in<nums.size();in++){
            if (nums[in] < one)
                one = nums[in];
            else if (one < nums[in] && nums[in] < two)
                two = nums[in];
            else if (two < nums[in])
                return true;
        }
        return false;
    }
};