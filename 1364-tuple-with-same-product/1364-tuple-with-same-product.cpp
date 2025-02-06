class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        unordered_map<int,int> freq;
        int maxi=0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int j=i+1;
            while(j<n){
                int prod = nums[i]*nums[j];
                j++;
                maxi += 8*freq[prod];
                freq[prod]++;
            }
        }
        return maxi;
    }
};