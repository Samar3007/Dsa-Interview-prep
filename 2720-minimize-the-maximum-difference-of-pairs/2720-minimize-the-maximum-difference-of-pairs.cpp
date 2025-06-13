class Solution {
public:
 
    
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int left=0, right=nums.back()-nums[0], mid;
        
        while(left<right){
            mid=left+(right-left)/2;
            
            int cnt=0;
            for(int i=0;i+1<nums.size();i++){
                if(abs(nums[i+1]-nums[i])<=mid){
                    cnt++;i++;
                }
            }   
            
            if(cnt>=p){
                right=mid;
            }
            else{
                left=mid+1;
            }
        }
        return left;
        
    }
};
 
/*Why does greedy work? Say we have sorted numbers i, j, k, l.

If pairs {i, k} and {j, l} are valid, then pairs {i, j} and {k, l} are also valid.

This is because if k - i <= m and l - j <= m, then l - k <= m + j - m - i and l - k <= j - i.

Since j - i <= m, therefore l - k <= m, so it is a valid pair.*/