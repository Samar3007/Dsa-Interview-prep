class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int ans=0;
        for(auto curr:nums){
            int complement=k-curr;
            if(freq[complement]>0){
                ans++;
                freq[complement]--;
            }
            else{
                freq[curr]++;
            }
        }
        return ans;
    }
};


