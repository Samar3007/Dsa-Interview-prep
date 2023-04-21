class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        int count=nums.size(),i=0;
        while(count>0){
            pq.push(nums[i]);
            count--;
            i++;
        }
        int f=k-1;
        while(f>0){
            pq.pop();
            f--;
        }
        return pq.top();
    }
};