class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even = 0, odd = 0;
        bool evenStart = nums[0]%2==0;

        int currSum = 0;
        int ans = 0;

        for(int it:nums){
            if(it%2) odd++;
            else even++;
            if(evenStart && it%2){
                currSum++;
                evenStart=!evenStart;
            }
            else if(!evenStart && it%2==0){
                currSum++;
                evenStart=!evenStart;
            }
        }
        
        ans = currSum+1;

        return max(max(odd,even),ans);
    }
};