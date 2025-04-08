class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size(), last = -1;
        int arr[101]={0};
        for(int i=n-1;i>=0;i--){
            arr[nums[i]]++;
            if(arr[nums[i]]>1){
                last = i;
                break;
            }
        }
        if(last == -1) return 0;
        int diff = last+1;
        int ans = diff/3;
        //cout<<last<<' '<<diff;
        if(diff%3) ans++;
        return ans;
    }
};