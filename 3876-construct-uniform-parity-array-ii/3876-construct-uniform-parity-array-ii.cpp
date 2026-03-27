class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini=*min_element(nums1.begin(), nums1.end());
        if(mini%2) return true;
        int oddCnt=0;
        
        for(int it:nums1){
            if(it%2) return false;
        }
        return true;
    }
};