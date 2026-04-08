class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
         // map stores: value -> index
        unordered_map<int, int> numMap; 
        
        for (int i = 0; i < nums.size(); ++i) {
            int currentNum = nums[i];
            int complement = target - currentNum;
            
            // Check if the complement exists in our map
            if (numMap.count(complement)) {
                // If found, we have our pair!
                // The complement's index is stored in the map, current num's index is 'i'
                return {numMap[complement], i};
            }
            
            // If complement not found, add the current number and its index to the map
            numMap[currentNum] = i;
        }
        
        // This line should technically not be reached given the problem constraints
        // (exactly one solution exists). But it's good practice for functions that
        // promise a return value.
        return {}; 
    }
};