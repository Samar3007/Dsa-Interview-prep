class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for(auto it:nums){
            pq.push(it);
        }
        int ans = 0;
        while(pq.top()<k && pq.size()>1){
            int min = pq.top();
            pq.pop();
            int max = pq.top();
            pq.pop();
            pq.push((long long)min*2 + max);
            ans++;
        }
        return ans;
    }
};